#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;
using namespace Automation::BDaq;
#define IterativeP -0.3
#define IterativeD -0.1

#define memZero(a) memset(a,0,sizeof(a))

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),//此处先拷贝父类构造函数，然后进行自己类的构造函数
        ui(new Ui::MainWindow),dataSaveBasePath("E:/PopWilCacher/data/")
{
    ui->setupUi(this);

    //试验状态信息
    logger=Logger::getInstance();
    startFlag=false;
    ui->btnStop->setEnabled(false);
    msCount=0;msStartCount=0;//此处一定要进行初始化，否则系统自动初始化一个值，导致出错！！
    model = new QStandardItemModel(ui->listView_eventInformation);

    sController=new StaticPositionController();
    sineController=new SinePositionController();

    //------------------load UArray------------------------
    memZero(OutUPreArray);memZero(OutUArray);
    memZero(ErrorPreArray);memZero(ErrorArray);
    memZero(SRefArray);memZero(SArray);
    memZero(VRefArray);memZero(VArray);
    memZero(ARefArray);memZero(AArray);

    testFunction();
//---------------------------将配置文件读入------------------------------------
    IniHelper *hh=new IniHelper;
    ConfigureParameterPCI iniSettingFile= hh->readFromPciIni("IniSetting/PCI1716.ini");
    configureAO=iniSettingFile.iniSettingAO;
    configureAI=iniSettingFile.iniSettingAI;
    log="from the iniFile AO is "+configureAO.deviceName+","+QString::number(configureAO.channelStart)+
            ","+QString::number(configureAO.channelCount)+","+QString::number(configureAO.valueRange);
    qDebug()<<log;logger->appendLogger("[debug] "+log);
    log="[info]通道参数文件载入成功！";
    addItemToListView(log);logger->appendLogger(log);

    //sPIDInfo=hh->readFromCtrlIni("../IniSetting/CtrlIni.ini");
    hh->readFromCtrlIni("IniSetting/CtrlIni.ini",sPIDInfo,sinePIDInfo);
    log="[info]控制参数文件载入成功！";
    addItemToListView(log);logger->appendLogger(log);

    systemInfo=hh->readFromSystemInfoIni("IniSetting/SystemInfo.ini");
    log="[info]系统参数文件载入成功 ";
    addItemToListView(log);logger->appendLogger(log);
    delete hh;

    log="system controlInterval:"+QString::number(systemInfo.contrlInterval)+
        " drawInterval:"+QString::number(systemInfo.drawInterval);
    qDebug()<<log;logger->appendLogger(log);
    PERFORMANCEINTERVAL=systemInfo.contrlInterval;
//------------------------------界面UI---------------------------------------------------------------
    setFixedSize(960, 900);
    setWindowIcon(QPixmap(":/Icon/Icon/dashboard.png"));

    ui->btnStart->setToolTip("开始");
    ui->btnStart->setStyleSheet("border-image:url(:Icon/Icon/startIcon.png)");
    ui->btnStart->setMask(QRegion(0,0,50,50,QRegion::Ellipse));
    ui->btnStop->setToolTip("停止");
    ui->btnStop->setStyleSheet("border-image:url(:Icon/Icon/stopIcon.png)");
    ui->btnStop->setMask(QRegion(0,0,50,50,QRegion::Ellipse));
    ui->btn_DO->setToolTip("开关");
    //---------------状态栏---------
    currentLabel=new QLabel;
    currentLabel->setMinimumSize(200,25);
    //currentLabel->setFrameShadow(QFrame::Sunken);
    currentLabel->setFrameShape(QFrame::WinPanel);
    ui->statusBar->addWidget(currentLabel);

    connect(ui->le_uk,SIGNAL(returnPressed()),ui->btn_out_uk,SLOT(click()));
    //connect(ui->le_uk,SIGNAL(returnPressed()),this,SLOT(on_btn_out_uk_clicked()));
    connect(ui->lineEdit_desPosition,SIGNAL(returnPressed()),this,SLOT(on_btn_static_comfirm_clicked()));
    setTabOrder(ui->le_mid,ui->le_mag);
    setTabOrder(ui->le_mag,ui->le_fre);
    setTabOrder(ui->le_fre,ui->le_cnt);

    ui->le_mid->setText("0");
    ui->le_mag->setText("5");
    ui->le_fre->setText("1");
    ui->le_cnt->setText("20");
    //------------地震波------------------------------------
    ////获取该路径下的所有文件
    QStringList earthquakeFiles= getFileNames("E:\\PopWilCacher\\EarthquakeWave");
    int earthquakeWaveCnt=earthquakeFiles.size();
    for(int i=0;i<earthquakeWaveCnt;i++){
        QString wave=earthquakeFiles[i];
        ui->cmb_earth->addItem(wave.left(wave.size()-4));
    }

    //------------------------------ENC7480-------------------------------------------------------------
    int d7480rtn= Enc7480_Init();
    log="雷塞采集卡数量"+QString::number(d7480rtn);
    qDebug()<<log;logger->appendLogger("[debug] "+log);
    if(d7480rtn < 1)
    {
        qDebug()<<"初始化ENC7480计数卡失败!";
        QMessageBox::information(NULL,"提示","初始化ENC7480计数卡失败",QMessageBox::Ok|QMessageBox::Cancel);
        log="[error]初始化ENC7480计数卡失败！";
        addItemToListView(log);logger->appendLogger(log);
        //this->close();
    }
    else{
        log="[info]初始化ENC7480计数卡成功！";
        addItemToListView(log);logger->appendLogger(log);
    }
    Enc7480_Set_Encoder(0,0);
//---------------------------------PCI1716初始化------------------------------------------------------------
    //DO 操作
    doInstant=new DoInstant();
    if (doInstant->getDeviceCount(configureAI.deviceName) == 0)
    {
        QMessageBox::information(this, tr("Warning Information"),tr("No device to support the currently demonstrated function!"));
        QCoreApplication::quit();
        log="[error]无法找到PCI设备！";
    }
    else
    {
        log="[info]初始化PCI-1716设备成功！";
    }
    qDebug()<<log;addItemToListView(log);logger->appendLogger(log);

    doInstant->setInstantDoPara(configureAO);
    doInstant->configure();

    quint8 portStates=doInstant->getDoState();
    log="DO read data is:"+QString::number(portStates);
    qDebug()<<log;logger->appendLogger("[debug] "+log);
    if(portStates)
    {
        ui->btn_DO->setStyleSheet("border-image:url(:Icon/Icon/switch_on.png)");
        log="[info]驱动已连接！";
        addItemToListView(log);logger->appendLogger(log);
    }
    else
    {
        ui->btn_DO->setStyleSheet("border-image:url(:Icon/Icon/switch_off.png)");
        log="[warning]驱动断开，请重新连接驱动！";
        addItemToListView(log);logger->appendLogger(log);
    }
    //电压输出InstanceAO
    aoInstant=new AoInstant();
    aoInstant->setInstantAoPara(configureAO);
    aoInstant->configure();
    outUToPCI(0);
    //InstantAI加速度当次采集
    aiInstant=new AiInstant();
    aiInstant->setInstantAiPara(configureAO);
    aiInstant->configure();
    //StreamingAi
    qDebug()<<configureAI.deviceName<<"  "<<configureAI.channelStart<<"  "<<configureAI.channelCount<<"  "<<configureAI.clockRatePerChan<<"  "<<configureAI.sectionLength;
    aiStreaming=new AiStreaming();
    aiStreaming->setStreamingAiPara(configureAI);
    aiStreaming->configure();
    //aiStreaming->start();
//---------------------------------绘图ChartViewer------------------------------------------------------------
    dPlot=new MyChartViewer(ui->drawFrame);
    dPlot->start();
    connect(ui->action_SaveAsPicture,SIGNAL(triggered(bool)),dPlot,SLOT(onSave(bool)));
    ui->tabWidget_pic->setCurrentIndex(0);
    ui->rbt_S->setChecked(true);
    m_ChartViewer=new QChartViewer(ui->tab_preview);
    //-------------------------------滤波初始化------------------------------
    sAvgFilter=new AvgFilter();
    vAvgFilter=new AvgFilter();
    aAvgFilter=new AvgFilter();
    sButtorFilter=new ButtorFilter();
    vButtorFilter=new ButtorFilter();
    aButtorFilter=new ButtorFilter();
//---------------------------------开启多媒体定时器------------------------------------------------------------
    timer=new PerformanceTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(slotFuction()));
    timer->start(PERFORMANCEINTERVAL);  //多媒体定时器开启
}

MainWindow::~MainWindow()
{
    outUToPCI(0);
    logger->writeAll();//将日志保存到文本文档
    dataSaveToTxt();
    outDataToExcel();

    Enc7480_Close();
    delete doInstant;
    delete aiInstant;
    delete aoInstant;
    delete aiStreaming;

    delete sAvgFilter;
    delete vAvgFilter;
    delete aAvgFilter;
    delete sButtorFilter;
    delete vButtorFilter;
    delete aButtorFilter;

    delete sController;
    delete sineController;

    delete m_ChartViewer;
    delete ui;
}
//------------------------------------------------------------------------------------------------------------------
//10ms多媒体定时器 100ms绘图
void MainWindow::slotFuction(){
    int i,startIndex;//开始之后第几次进入定时器
    static double sCurrent_1=0;//static修饰的静态局部变量只执行初始化一次
    double sCurrent,vCurrent,aCurrent,refPosition,uk;
    double series0,series1,elapsedTime,elapseStartTime;
    //------------------------------------update time in StateBar---------------------------------------------
    if (msCount%1000==0){
        QDateTime time = QDateTime::currentDateTime();
        QString str = "系统时间："+time.toString("yyyy-MM-dd hh:mm:ss");
        currentLabel->setText(str);
    }
    //---------------------------------Read Real Displacement------------------------------------------------------
    sCurrent=getPosition(0);
    sCurrent=sin(2*PI*msCount/1000)+sin(2*PI*50*msCount/1000);
    //sCurrent=sin(2*PI*2*msCount/1000);
    sCurrent=sAvgFilter->filter(sCurrent);
    if (fabs(sCurrent)>systemInfo.maxAbsolutePosition) outUToPCI(0);//Protected Program
    //---------------------------------将数据放入缓冲区---------------------------------------------------
    msCount+=PERFORMANCEINTERVAL;
    if (startFlag) msStartCount+=PERFORMANCEINTERVAL;

    startIndex=msStartCount/PERFORMANCEINTERVAL;
    elapsedTime=msCount / 1000.0;
    elapseStartTime=msStartCount/1000.0;
    //------------------------------------差分计算速度------------------------------
    vCurrent=(sCurrent-sCurrent_1)/(PERFORMANCEINTERVAL/1000.0);
    vCurrent=vAvgFilter->filter(vCurrent);
    vCurrent=vButtorFilter->filter(vCurrent);
    sCurrent_1=sCurrent;
    //------------------------------------读取加速度---------------------------------
    aCurrent=aiInstant->getAcc();//获取单个加速度
    //aCurrent=aiStreaming->getAcc();//通过SteamingAi方式获取加速度
    aCurrent=aAvgFilter->filter(aCurrent);
    aCurrent=aButtorFilter->filter(aCurrent);
    //qDebug()<<"当前加速度是："<<aCurrent;
    //------------------------------------------------------------------
    if(msCount%10==0){
        SArray[++dataCnt]=sCurrent;//将位移数据存进数组，从1开始计数
        VArray[dataCnt]=vCurrent;
        AArray[dataCnt]=aCurrent;
    }
    series0=sCurrent;series1=sCurrent;
    if(!startFlag) return;
    //---------------------------AO输出---------------------------------------------------------
    //Trajactory:static value 最佳参数：P=-0.25，I=-0，D=-0.1；
    //P=-0.25,I=0,D=-0.5 滤波，调零之后
    if(globalFlag==StaticPosionFlag){//PID静态位移控制——移动到指定位置
        refPosition=0;uk=sController->getUk(sCurrent,refPosition);
        //qDebug()<<"refPosition:"<<refPosition<<"sCurrent:"<<sCurrent<<" uk:"<<uk;
        series0=refPosition;series1=sCurrent;
        outUToPCI(uk);
    }
    //trajectory:sine wave   Parameter:P=-0.25,I=-0.001,D=-0.1
    static int sinePreCnt=1;
    if(globalFlag==SineWaveFlag){
        if(sinePreCnt<=dataRefCnt)
            refPosition=SRefArray[sinePreCnt++];
        else refPosition=0;
        uk=sineController->getUk(sCurrent,refPosition);
        qDebug()<<"sinePreCnt"<<sinePreCnt<<"refPosition:"<<refPosition<<"sCurrent:"<<sCurrent<<" uk:"<<uk;
        series0=refPosition;series1=sCurrent;
        outUToPCI(uk);
    }
//   if(iterativeControl_Flag)
//   {
//       PosVref=10*sin(2*PI*(elapseStartTime));
//       series1=PosVref;
//       SPrefArray[startIndex]=PosVref;
//       ErrorArray[startIndex]=PosVref-sCurrent;
//       //闭环PD迭代控制
//       OutUArray[startIndex]=OutUPreArray[startIndex]+IterativeP*ErrorArray[startIndex]+IterativeD*(ErrorArray[startIndex]-ErrorArray[startIndex-1]);
//       //开环PD迭代控制
//       //OutUArray[startIndex]=OutUPreArray[startIndex]+IterativeP*ErrorPreArray[startIndex]+IterativeD*(ErrorPreArray[startIndex]-ErrorPreArray[startIndex-1]);
//       //选择采用之前的参数
//       //OutUArray[startIndex]=OutUPreArray[startIndex];
//       outUToPCI(OutUArray[startIndex]);
//       qDebug()<<"uk="<<OutUArray[startIndex]<<"  ek="<<ErrorArray[startIndex];
//   }
    if(msCount%100==0){//保留三位小数
        ui->lcd_S->display(QString::number(sCurrent,'f',3));
        ui->lcd_V->display(QString::number(vCurrent,'f',3));
        ui->lcd_A->display(QString::number(aCurrent,'f',3));
    }
    //100ms将数据存入绘图缓冲区
    if(msCount%10==0)
        buffer.put(DataPacket(elapsedTime,series0,series1));
}

void MainWindow::on_btnStart_clicked()
{
    ui->tabWidget_pic ->setCurrentIndex(0);//展示绘图页面，而不是预览界面
    //Icon以及Enable变化
    ui->btnStart->setStyleSheet("border-image:url(:Icon/Icon/startIconClicked.png)");
    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(true);
    ui->btnStop->setStyleSheet("border-image:url(:Icon/Icon/stopIcon.png)");

    startFlag=true;
    //PID静态位移控制开始
    //timer->start(PERFORMANCEINTERVAL);  //多媒体定时器开启
    msStartCount=0;
}

void MainWindow::on_btnStop_clicked()
{
    if(!startFlag) return;
    ui->btnStart->setStyleSheet("border-image:url(:Icon/Icon/startIcon.png)");
    ui->btnStart->setEnabled(true);
    ui->btnStop->setStyleSheet("border-image:url(:Icon/Icon/stopIconClicked.png)");
    //---------------------AO------------------------------
    outUToPCI(0);
    startFlag=false;
    //---------------------AI------------------------------
    ui->le_uk->setText("0");
    //dataSaveToTxt();
}

void MainWindow::on_action_Quit_triggered()
{
    this->close();
}

void MainWindow::on_action_ToolFlag_triggered()
{
    if (ui->action_ToolFlag->isChecked())
        ui->toolBar->setVisible(false);
    else
        ui->toolBar->setVisible(true);
}

void MainWindow::on_action_StatusFlag_triggered()
{
    if (ui->action_StatusFlag->isChecked())
        ui->statusBar->setVisible(false);
    else
        ui->statusBar->setVisible(true);
}

void MainWindow::on_action_About_triggered()
{
    AboutForm *aboutForm=new AboutForm;
    aboutForm->show();
}

void MainWindow::on_action_HelpF1_triggered()
{/*
    QDesktopServices desktopServices;
    QString strUrl=QCoreApplication::applicationDirPath () ;
    strUrl=QString("D:/Popwil/PopWil/Help/VCSHelp.chm").arg (strUrl);
    QUrl qqq(strUrl);
    desktopServices.openUrl(qqq);
    */
}

void MainWindow::on_action_ChannelParameters_triggered()
{
    //首先进入构造函数
    ConfigureDialog dialog;
    dialog.SetConfigureParameterAO(configureAO,configureAI);
    int resultDialog = dialog.exec();
    if (resultDialog == QDialog::Rejected){
        //exit(0);
    }
    else if(resultDialog == QDialog::Accepted){
        SetConfigureParameterAO(dialog.GetConfigureParameter());\
        SetConfigureParameterAI(dialog.GetConfigureParameterAI());
        qDebug()<<"the data from configureDialog is :";
        qDebug()<<"haha"<<configureAO.deviceName<<configureAO.channelStart<<configureAO.channelCount<<configureAO.valueRange;
        qDebug()<<"haha"<<configureAI.deviceName<<configureAI.channelStart<<configureAI.channelCount<<configureAI.valueRange<<configureAI.clockRatePerChan<<configureAI.sectionLength;
        aiInstant->setInstantAiPara(configureAO);//将修改的参数重新配置
        aoInstant->setInstantAoPara(configureAO);
    }
}

void MainWindow::on_action_ControlParameters_triggered()
{
    CtrlDialog dialog;
    dialog.setPIDParameter();//将参数载入到窗体中
    int resultDialog = dialog.exec();
    if (resultDialog == QDialog::Rejected){
        //exit(0);
    }
    else {
        qDebug()<<"PID 参数是:"<<sPIDInfo.SP<<"  "<<sPIDInfo.SI<<"  "<<sPIDInfo.SD;
        qDebug()<<"sinePID 参数是:"<<sinePIDInfo.SP<<"  "<<sinePIDInfo.SI<<"  "<<sinePIDInfo.SD;
    }
}

void MainWindow::on_action_SaveAsDefalut_triggered()
{
    //------------------------------PCI1716.ini---------------------------------------
    ConfigureParameterPCI tmp;
    tmp.iniSettingAI=configureAI;
    tmp.iniSettingAO=configureAO;
    IniHelper *tmpHelper=new IniHelper;
    QString info;
    bool result=tmpHelper->writeToPCIIni("IniSetting/PCI1716.ini",tmp);
    if (result)
    {
        info="[info]PCI1716.ini已保存为默认设置！";
    }
    else
        info="[error]PCI1716.ini保存失败";
    qDebug()<<info;
    addItemToListView(info);logger->appendLogger(info);
    delete tmpHelper;
    //------------------------------CtrlIni.ini---------------------------------------
    tmpHelper=new IniHelper;
    result=tmpHelper->writeToCtrlIni("IniSetting/CtrlIni.ini",sPIDInfo,sinePIDInfo);
    if (result)
    {
        info="[info]CtrlIni.ini已保存为默认设置！";
    }
    else
        info="[error]CtrlIni.ini保存失败";
    qDebug()<<info;
    addItemToListView(info);logger->appendLogger(info);
    delete tmpHelper;
    //------------------------------SystemInfo.ini---------------------------------------
    tmpHelper=new IniHelper;
    result=tmpHelper->writeToSystemInfoIni("IniSetting/SystemInfo.ini",systemInfo);
    if (result)
    {
        info="[info]SystemInfo.ini已保存为默认设置！";
    }
    else
        info="[error]SystemInfo.ini保存失败";
    qDebug()<<info;
    addItemToListView(info);logger->appendLogger(info);
    delete tmpHelper;
}

void MainWindow::on_action_Identity_triggered()
{
    RBF *rbf=new RBF();
    rbf->show();
}

void MainWindow::on_actionAction_SystemSettings_triggered()
{
    SystemSettings dialog;
    dialog.setSystemInfo();
    int resultDialog = dialog.exec();
    if (resultDialog == QDialog::Rejected)
    {
        //exit(0);
    }
    else if(resultDialog == QDialog::Accepted)
    {
        qDebug()<<"new setted system info is :"<<systemInfo.contrlInterval<<systemInfo.drawInterval;
    }
}

void MainWindow::addItemToListView(QString str)
{
    QStandardItem *item = new QStandardItem(str);
    QColor color;
    switch (str.toLatin1().data()[1])
    {
        case 'i':color=Qt::white;//[info]
                 break;
        case 'w':color=Qt::yellow;//[warning]
                break;
        case 'e':color=Qt::red;//[error]
                break;
        default:color=Qt::white;
    }
    item->setBackground(QBrush(color));

    model->appendRow(item);
    ui->listView_eventInformation->setModel(model);
    ui->listView_eventInformation->scrollToBottom();
}

void MainWindow::outUToPCI(double value)
{
    double vBias=-0.003;
    double MAXOUTU=systemInfo.maxOutU;
    //vBias=0;
    value+=vBias;

    value=value>MAXOUTU?MAXOUTU:value;
    value=value<-MAXOUTU?-MAXOUTU:value;

    aoInstant->outU(value);
    //addItemToListView("输出电压"+QString::number(value));
}

void MainWindow::on_btn_clearZero_clicked()
{
     Enc7480_Set_Encoder(0,0);
     ui->lcd_S->display(QString::number(0,'f',3));
}

void MainWindow::testFunction()
{
    /*for (int i=0;i<100;i++)
    {
        OutUArray[i]=sin(0.05*PI*i);
        OutUPreArray[i]=-OutUArray[i];
    }
    qDebug()<<"相关系数是："<<MathTool::coeff(OutUArray,OutUPreArray,100);*/

//    FILE *f;
//    f=fopen(dataSavePath.toLatin1(),"rt");
//    if(f==NULL)
//    {
//        qDebug()<<dataSavePath+"文件打开失败";
//        return;
//    }
//    else
//    {
//        qDebug()<<dataSavePath+"文件打开成功！";
//        int j;
//        fscanf(f,"\n");
//        for(i=1;i<=1000;i++)
//            fscanf(f,"%d %lf %lf %lf %lf\n",&j,&OutUPreArray[i],&ErrorPreArray[i],&SArray[i],&VArray[i]);
//        //for (i=1;i<=6000;i++)
//            //qDebug()<<i<<":"<<OutUPreArray[i]<<"   "<<ErrorPreArray[i];
//    }
//    fclose(f);

//        QXlsx::Document xlsx("book1.xlsx");/*打开一个book1的文件*/
//        QXlsx::Format format1;/*设置该单元的样式*/
//        format1.setFontColor(QColor(Qt::red));/*文字为红色*/
//        format1.setPatternBackgroundColor(QColor(152,251,152));/*北京颜色*/
//        format1.setFontSize(15);/*设置字体大小*/
//        format1.setHorizontalAlignment(QXlsx::Format::AlignHCenter);/*横向居中*/
//        format1.setBorderStyle(QXlsx::Format::BorderDashDotDot);/*边框样式*/
//        xlsx.write("A1", "Hello Qt!", format1);/*写入文字，应该刚才设置的样式*/
//        xlsx.write(2, 1, 12345, format1);/*写入文字，应该刚才设置的样式*/
//        QXlsx::Format format2;/*重新设置另一个单元的样式*/
//        format2.setFontBold(true);/*设置加粗*/
//        format2.setFontUnderline(QXlsx::Format::FontUnderlineDouble);/*下双划线*/
//        format2.setFillPattern(QXlsx::Format::PatternLightUp);/*填充方式*/
//        xlsx.write("A4", "=44+33", format2);/*写入文字，应该刚才设置的样式*/
//        xlsx.write("C4", true, format2);
//        if(!xlsx.selectSheet("ziv")){/*在当前打开的xlsx文件中，找一个名字为ziv的sheet*/
//            xlsx.addSheet("ziv");//找不到的话就添加一个名为ziv的sheet
//        }
//        for (int i=10; i<20; ++i) {/*写入一串数字*/
//            xlsx.write(i, 1, i*i*i);   //A10:A19
//            xlsx.write(i, 2, i*i); //B10:B19
//            xlsx.write(i, 3, i*i-1); //C10:C19
//        }
//        QXlsx::Chart *pieChart = xlsx.insertChart(3, 5, QSize(300, 300));/*在3行5列的位置插入一个图标*/
//        pieChart->setChartType(QXlsx::Chart::CT_Pie);/*插入一个饼形图*/
//        pieChart->addSeries(QXlsx::CellRange("A10:A19"));/*饼形图添加数据*/
//        pieChart->addSeries(QXlsx::CellRange("B10:B19"));
//        pieChart->addSeries(QXlsx::CellRange("C10:C19"));
//        QXlsx::Chart *barChart = xlsx.insertChart(3, 13, QSize(300, 300));/*在3行13列的位置插入一个图标*/
//        barChart->setChartType(QXlsx::Chart::CT_Bar);/*条形图*/
//        barChart->addSeries(QXlsx::CellRange("A10:C19"));/*给条形图加入数据*/
//        xlsx.saveAs("book1.xlsx");/*保存*/
//        QXlsx::Document xlsx2("Book1.xlsx");/*复制book1到book2*/
//        xlsx2.saveAs("Book2.xlsx");
}

void MainWindow::on_btn_static_comfirm_clicked()
{
    double sCurrent=getPosition(0);//这个就是当前的基准电压
    double desPosition=ui->lineEdit_desPosition->text().toDouble();
    sController->configure(desPosition,sCurrent);
    globalFlag=StaticPosionFlag;
}

void MainWindow::on_btn_DO_clicked()
{
    quint8 status;
    if(doInstant->getDoState()){
        ui->btn_DO->setStyleSheet("border-image:url(:Icon/Icon/switch_off.png)");
        status = 0;
        log="[warning]驱动已经断开！";
        addItemToListView(log);logger->appendLogger(log);
    }
    else{
        ui->btn_DO->setStyleSheet("border-image:url(:Icon/Icon/switch_on.png)");
        status=1;
        log="[info]驱动已连接！";
        addItemToListView(log);logger->appendLogger(log);
    }
    doInstant->setDoState(status);
}

void MainWindow::outDataToExcel()
{
    int count=100;
//   QXlsx::Document xlsx;
//   if(!xlsx.selectSheet("data"))
//       xlsx.addSheet("data");
//   xlsx.write("A1", "编号");
//   xlsx.write("B1","输出/V");
//   xlsx.write("C1","误差/mm");
//   xlsx.write("D1","参考位移/mm");
//   xlsx.write("E1","位移/mm");
//   xlsx.write("F1","速度/mm/s");
//   for (int i=1;i<=count;i++)
//   {
//       xlsx.write(i+1,1,i);
//       xlsx.write(i+1,2,OutUArray[i]);
//       xlsx.write(i+1,3,ErrorArray[i]);
//       xlsx.write(i+1,4,SRefArray[i]);
//       xlsx.write(i+1,5,SArray[i]);
//       xlsx.write(i+1,6,VArray[i]);
//   }
//   QXlsx::Chart *lineChart = xlsx.insertChart(3, 8, QSize(900, 300));
//   lineChart->setChartType(QXlsx::Chart::CT_Line);
//   lineChart->addSeries(QXlsx::CellRange("A2:B"+QString::number(count)));
//   xlsx.saveAs("E:\\data.xlsx");/*保存*/
   log="[info]数据保存E:\\data.xlsx成功";
   addItemToListView(log);logger->appendLogger(log);
}

void MainWindow::dataSaveToTxt()
{
    QString message;
    QString path=dataSaveBasePath;
    path += QDateTime::currentDateTime().toString("yyyyMMdd_hhmm");
    path += ".txt";
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        message="[error]:文件"+path+"创建失败";
        addItemToListView(message);logger->appendLogger(message);
        return;
    }

    QTextStream out(&file);
    out.setCodec(QTextCodec::codecForName("UTF-8"));
    message="[info]:文件"+path+"创建成功！";
    addItemToListView(message);logger->appendLogger(message);

    //---------------data---------------
    out<<QString("采样点数： ")<<dataCnt<<endl;
    out<<QString("i     输出/V     误差/mm     参考位移/mm      位移/mm     速度/mm/s     加速度/mm/ss")<<endl;
    for(int i=1;i<=dataCnt;i++)
        out<<i<<"   "<<OutUArray[i]<<"   "<<ErrorArray[i]<<"   "<<SRefArray[i]<<"   "<<SArray[i]<<"   "<<VArray[i]<<"   "<<AArray[i]<<endl;
    double tp=MathTool::coeff(SArray,SRefArray,dataCnt);
    out<<QString("位移的相关系数是：")<<tp<<endl;
    qDebug()<<tp;

    message="[info]:实验数据保存成功，位置在"+path;
    addItemToListView(message);logger->appendLogger(message);
    file.close();
}
//重写关闭事件
void MainWindow::closeEvent(QCloseEvent *event){

    int ret=QMessageBox::information(NULL,"提示信息","请确实是否退出操作界面？",
                                     QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
    switch (ret) {
      case QMessageBox::Ok:event->accept();break;
      case QMessageBox::Cancel:event->ignore();break;
    }
}

void MainWindow::on_action_Pointer_triggered()
{
    dPlot->onMouseUsageChanged(Chart::MouseUsageScroll);
}

void MainWindow::on_action_ZoomIn_triggered()
{
    dPlot->onMouseUsageChanged(Chart::MouseUsageZoomIn);
}

void MainWindow::on_action_ZoomOut_triggered()
{
    dPlot->onMouseUsageChanged(Chart::MouseUsageZoomOut);
}

double MainWindow::getPosition(int direct){
    int x_position = Enc7480_Get_Encoder(direct);
    //sCurrent=x_position*(-0.0024)-0.012;
    double position=x_position*(-0.0024);
    return position;
}

void MainWindow::on_btn_out_uk_clicked()
{
    outUToPCI(ui->le_uk->text().toDouble());
}

void MainWindow::on_btn_sine_load_clicked()
{
    double mid    =ui->le_mid->text().toDouble();//中心坐标
    double mag    =ui->le_mag->text().toDouble();//幅值
    double fs     =ui->le_fre->text().toDouble();//频率
    double sineCnt=ui->le_cnt->text().toDouble();//重复次数
    //生成参考波形
    dataRefCnt=0;
    double elapseStartTime=0,sRef;
    while(true){
        if(elapseStartTime>3+sineCnt/fs) break;
        if(elapseStartTime<=3)
            sRef=mag/(3+1/fs/4)*elapseStartTime*sin(2*PI*fs*elapseStartTime)+mid;
        else sRef=mag*sin(2*PI*fs*elapseStartTime)+mid;
        SRefArray[++dataRefCnt]=sRef;//SRefArray从1开始计数
        qDebug()<<"elapseStartTime:"<<elapseStartTime<<" sRef="<<sRef;
        elapseStartTime += systemInfo.contrlInterval*1.0/1000;
    }
    Enc7480_Set_Encoder(0,0);
    globalFlag=SineWaveFlag;
}

void MainWindow::on_btn_preview_earth_clicked()
{
    ui->tabWidget_pic->setCurrentIndex(1);//展示预览界面
    QString earthFileName=ui->cmb_earth->currentText();
    QString earthFilePath="E:\\PopWilCacher\\EarthquakeWave\\"+earthFileName+".txt";
    getEarthquakeWave(earthFilePath);//将地震波数据载入到Ref数组中
//---------------------预览绘图-----------------------------------
    double index[10000];
    for(int i=0;i<dataRefCnt;i++)index[i]=i*1.0/100;
    m_ChartViewer->setGeometry(5, 25, 640, 500);
    XYChart *c = new XYChart(650, 480);//画布大小，包括图标和标题等
    c->setPlotArea(30, 30, c->getWidth() - 41, c->getHeight() - 60, c->linearGradientColor(0, 30, 0,
       c->getHeight() - 50, 0xf0f6ff, 0xa0c0ff), -1, 0xffffff, 0xffffff);
    c->addTitle(earthFileName.toLatin1(), "simsun.ttc", 18);
    c->setBackground(0xccccff,0x000000);
    if(ui->rbt_S->isChecked()){
        c->addLineLayer(DoubleArray(SRefArray+1,dataRefCnt));//添加y轴数据
        c->addText(5, 5, "S/mm", "timesbi.ttf", 11, 0xff0000);
    }
    if(ui->rbt_V->isChecked()){
        c->addLineLayer(DoubleArray(VRefArray+1,dataRefCnt));//添加y轴数据
        c->addText(5, 5, "V/mm/s", "timesbi.ttf", 11, 0xff0000);
    }
    if(ui->rbt_A->isChecked()){
        c->addLineLayer(DoubleArray(ARefArray+1,dataRefCnt));//添加y轴数据
        c->addText(5, 5, "A/g", "timesbi.ttf", 11, 0xff0000);
    }
    c->xAxis()->setLabels(DoubleArray(index,dataRefCnt));//添加x轴数据，有点类似C里的指针操作
    c->addText(630, 450, "t/s", "timesbi.ttf", 11, 0xff0000);
    c->xAxis()->setLabelStep(500);//x轴绘图间隔

    m_ChartViewer->setChart(c);
    delete c;
    m_ChartViewer->show();
}

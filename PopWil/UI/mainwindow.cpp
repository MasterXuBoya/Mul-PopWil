#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ToolFromMatlab.h"
#include "ssitool.h"

using namespace std;
using namespace Automation::BDaq;

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),//此处先拷贝父类构造函数，然后进行自己类的构造函数
        ui(new Ui::MainWindow),dataSaveBasePath("E:/PopWilCacher/data/")
{
    ui->setupUi(this);

    englishTranslator=new QTranslator(this);
    bool b = englishTranslator->load(":/translators/lang_English.qm");
    if(b) qDebug()<<"lang_English load sucess";
    else qDebug()<<"lang_English load failed";


    QFile file(":/qss/stylesheet.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    qApp->setStyleSheet(styleSheet);
    file.close();

    //试验状态信息
    logger=Logger::getInstance();
    startFlag=false;
    ui->btnStop->setEnabled(false);
    msCount=0;
    msStartCount=msStartCount_Ref=elapseStartTime=0;refIndex=1;//此处一定要进行初始化，否则系统自动初始化一个值，导致出错！！

    model = new QStandardItemModel(ui->listView_eventInformation);

    //------------------load UArray------------------------
    dataCnt=0;refData.refCnt=ydData.refCnt=segData.refCnt=refSegData.refCnt=0;
    segCnt=0;//seg个数，全局变量
    for(int i=0;i<MAXDATACOUNT;i++){//此处不适用memset，容易出错
        //下面三组数组以dataCnt作为index
        OutUPreArray[i]=OutUArray[i]=ErrorPreArray[i]=ErrorArray[i]=0;
        SRefArray[i]=VRefArray[i]=ARefArray[i]=0;
        SArray[i]=VArray[i]=AArray[i]=0;

        refData.SRef[i]=refData.VRef[i]=refData.ARef[i]=0;
        ydData.SRef[i]=ydData.VRef[i]=ydData.ARef[i]=0;
        segData.SRef[i]=segData.VRef[i]=segData.ARef[i]=0;
        refSegData.SRef[i]=refSegData.VRef[i]=refSegData.ARef[i]=0;

    }
    //系统传递函数变量systemModel初始化
    systemModel.Nfft=systemModel.Fs=0;
    for(int i=0;i<2048;i++)
        systemModel.Txy_real[i]=systemModel.Txy_imag[i]=systemModel.F[i]=0;
    //testFunction();
//---------------------------将配置文件读入------------------------------------
    IniHelper *hh=new IniHelper;
    ConfigureParameterPCI iniSettingFile= hh->readFromPciIni("E://PopWilCacher//IniSetting//PCI1716.ini");
    configureAO=iniSettingFile.iniSettingAO;
    configureAI=iniSettingFile.iniSettingAI;
    log="from the iniFile AO is "+configureAO.deviceName+","+QString::number(configureAO.channelStart)+
            ","+QString::number(configureAO.channelCount)+","+QString::number(configureAO.valueRange);
    qDebug()<<log;logger->appendLogger("[debug] "+log);
    log=tr("[info] 通道参数文件载入成功！");
    addItemToListView(log);logger->appendLogger(log);

    //sPIDInfo=hh->readFromCtrlIni("../IniSetting/CtrlIni.ini");
    hh->readFromCtrlIni("E://PopWilCacher//IniSetting//CtrlIni.ini");
    log=tr("[info] PID控制参数文件载入成功！");
    addItemToListView(log);logger->appendLogger(log);

    hh->readFromTVCIno("E://PopWilCacher//IniSetting//TvcInfo.ini");
    log=tr("[info] 三参量控制参数文件载入成功！");
    addItemToListView(log);logger->appendLogger(log);

    systemInfo=hh->readFromSystemInfoIni("E://PopWilCacher//IniSetting//SystemInfo.ini");
    log=tr("[info] 系统参数文件载入成功 ");
    addItemToListView(log);logger->appendLogger(log);
    delete hh;

    log="system controlInterval:"+QString::number(systemInfo.contrlInterval)+
        " drawInterval:"+QString::number(systemInfo.drawInterval);
    qDebug()<<log;
    PERFORMANCEINTERVAL=systemInfo.contrlInterval;
    refData.refCnt=0;refData.dataRefSampleT=PERFORMANCEINTERVAL;//自己生成的参考波形的采样频率就是控制频率
//------------------------------界面UI---------------------------------------------------------------
    setFixedSize(960, 900);
    setWindowIcon(QPixmap(":/Icon/Icon/main.ico"));

    ui->btnStart->setToolTip(tr("开始"));
    ui->btnStart->setMask(QRegion(0,0,50,50,QRegion::Ellipse));
    ui->btnStop->setToolTip(tr("停止"));
    ui->btnStop->setMask(QRegion(0,0,50,50,QRegion::Ellipse));
    ui->btn_DO->setToolTip(tr("开关"));
    ui->btn_load->setToolTip(tr("载入数据"));
    //---------------状态栏---------
    currentLabel=new QLabel;
    currentLabel->setMinimumSize(150,20);
    currentLabel->setAlignment(Qt::AlignCenter);
    //currentLabel->setFrameShadow(QFrame::Sunken);
    currentLabel->setFrameShape(QFrame::WinPanel);
    ui->statusBar->addWidget(currentLabel);

    ui->statusBar->addWidget(ui->progressBar);
    ui->progressBar->setGeometry(150,0,200,20);
    ui->progressBar->setRange(1,100);
    ui->progressBar->setValue(1);

    connect(ui->le_uk,SIGNAL(returnPressed()),ui->btn_out_uk,SLOT(click()));
    //connect(ui->le_uk,SIGNAL(returnPressed()),this,SLOT(on_btn_out_uk_clicked()));
    connect(ui->lineEdit_desPosition,SIGNAL(returnPressed()),this,SLOT(on_btn_static_comfirm_clicked()));
    setTabOrder(ui->le_mid,ui->le_mag);
    setTabOrder(ui->le_mag,ui->le_fre);
    setTabOrder(ui->le_fre,ui->le_cnt);
    //迭代控制台
    iterativeControlUI=new IterativeControlMainWindow();
    calibrationDialog=new calibration();
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
        log=tr("[error] 初始化ENC7480计数卡失败！");
        addItemToListView(log);logger->appendLogger(log);
        //this->close();
    }
    else{
        log=tr("[info] 初始化ENC7480计数卡成功！");
        QMessageBox::information(NULL,"提示","初始化ENC7480计数卡成功",QMessageBox::Ok|QMessageBox::Cancel);
        addItemToListView(log);logger->appendLogger(log);
    }
    Enc7480_Set_Encoder(0,0);

    //SSI位移采集卡
    bool ssiRet=ImportDLL_ConnectToDev();
    if(ssiRet){
//        writeData( 16, 25);
//        writeData( 17, 25);
//        writeData( 18, 25);
//        writeData( 19, 25);
    }else{
        QMessageBox::information(NULL,"提示","NO SSI Device Found!",QMessageBox::Ok|QMessageBox::Cancel);
    }
//---------------------------------PCI1716初始化------------------------------------------------------------
    //DO 操作
    doInstant=new DoInstant();
    if (doInstant->getDeviceCount(configureAI.deviceName) == 0){
        QMessageBox::information(this, tr("Warning Information"),tr("No device to support the currently demonstrated function!"));
        QCoreApplication::quit();
        log=tr("[error] 无法找到PCI设备！");
    }
    else log=tr("[info] 初始化PCI-1716设备成功！");
    qDebug()<<log;addItemToListView(log);logger->appendLogger(log);

    doInstant->setInstantDoPara(configureAO);
    doInstant->configure();

    quint8 portStates=doInstant->getDoState();
    log="DO read data is:"+QString::number(portStates);
    qDebug()<<log;logger->appendLogger("[debug] "+log);
    if(portStates){
        ui->btn_DO->setStyleSheet("QPushButton#btn_DO{border-image:url(:Icon/Icon/switch_on.png)}");
        log=tr("[info] 驱动已连接！");
        addItemToListView(log);logger->appendLogger(log);
    }
    else{
        ui->btn_DO->setStyleSheet("QPushButton#btn_DO{border-image:url(:Icon/Icon/switch_off.png)}");
        log=tr("[warning] 驱动断开，请重新连接驱动！");
        addItemToListView(log);logger->appendLogger(log);
    }
    //电压输出InstanceAO
    aoInstant=new AoInstant();
    aoInstant->setInstantAoPara(configureAO);
    aoInstant->configure();
    outUToPCI(0.0);
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
    ui->rbt_S_plot->setChecked(true);
    m_ChartViewer=new QChartViewer(ui->tab_preview);

    sDisplayBuffer.setDelayCnt(displayDelay.sDelay);
    vDisplayBuffer.setDelayCnt(displayDelay.vDelay);
    aDisplayBuffer.setDelayCnt(displayDelay.aDelay);//此时都是2
    connect(ui->rbt_S,SIGNAL(clicked(bool)),this,SLOT(on_btn_preview_clicked()));
    connect(ui->rbt_V,SIGNAL(clicked(bool)),this,SLOT(on_btn_preview_clicked()));
    connect(ui->rbt_A,SIGNAL(clicked(bool)),this,SLOT(on_btn_preview_clicked()));
    //-------------------------------滤波初始化------------------------------
    memset(sCurrentThreeFreedom,0,sizeof(sCurrentThreeFreedom));
    m_filter_length=30;
    sAvgFilter=new AvgFilter(m_filter_length);
    sAvgFilterThreeFreedom=new AvgFilter[DISSENSORCOUNT]();
    for(int i=0;i<DISSENSORCOUNT;i++)
        sAvgFilterThreeFreedom[i].setLag(m_filter_length);
    vAvgFilter=new AvgFilter(m_filter_length);
    aAvgFilter=new AvgFilter(m_filter_length);

    sHMAFilter=new HMAFilter(m_filter_length);
    vHMAFilter=new HMAFilter(m_filter_length);
    aHMAFilter=new HMAFilter(m_filter_length);

    sButtorFilter=new ButtorFilter();
    vButtorFilter=new ButtorFilter();
    aButtorFilter=new ButtorFilter();

    sController=new StaticPositionController();

    sinePIDController=new PIDController();
    sinePIDController->setPIDPara(sinePIDInfo);
    sinePIDControllerThreeFreedom=new PIDController[DISSENSORCOUNT];
    for(int i=0;i<DISSENSORCOUNT;i++)
        sinePIDControllerThreeFreedom[i].clear();
    sinePIDControllerThreeFreedom[0].setPIDPara(pid3Info.dis);
    sinePIDControllerThreeFreedom[1].setPIDPara(pid3Info.vel);
    sinePIDControllerThreeFreedom[2].setPIDPara(pid3Info.acc);

    accPIDController=new PIDController();
    accPIDController->setPIDPara(accPIDInfo);

    //两种方式实现的三参量控制方法
    tvcController=new TVController();
    tvcController->setTvcPara(tvcInfo);

    pid3Controller=new PID3Controller();
    pid3Controller->setPara(pid3Info);
    pid3Weight.setDate(1.0/3,1.0/3,1.0/3);

    ui->cmb_contr_method->setCurrentIndex(0);
    ui->listWidget_waveMode->setCurrentRow(0);
    controlMethod=PIDMethod;
    double scur=getPosition(0);//进入程序即进行静态位移控制
    sController->configure(0,scur);
    waveMode=StaticPosionFlag;

//---------------------------------开启多媒体定时器------------------------------------------------------------
    timer=new PerformanceTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(slotFuction()));
    timer->start(PERFORMANCEINTERVAL);  //多媒体定时器开启
    qDebug()<<"Mainwindow构造函数执行结束";
}

MainWindow::~MainWindow()
{
    outUToPCI(0.0);

    dataSaveToTxt();
    outDataToExcel();
    logger->writeAll();//将日志保存到文本文档

    Enc7480_Close();
    delete doInstant;
    delete aiInstant;
    delete aoInstant;
    delete aiStreaming;

    delete sAvgFilter;
    delete []sAvgFilterThreeFreedom;
    delete vAvgFilter;
    delete aAvgFilter;
    delete sButtorFilter;
    delete vButtorFilter;
    delete aButtorFilter;
    delete sHMAFilter;
    delete vHMAFilter;
    delete aHMAFilter;

    delete sController;
    delete sinePIDController;
    delete []sinePIDControllerThreeFreedom;
    delete accPIDController;
    delete tvcController;
    delete pid3Controller;
    //delete earthquakePIDController;

    DisConnectToDev_FreeDll();//断开SSI连接
    delete m_ChartViewer;
    delete iterativeControlUI;
    delete calibrationDialog;
    delete ui;
}
//------------------------------------------------------------------------------------------------------------------
//2ms多媒体定时器 100ms绘图
void MainWindow::slotFuction(){
    static double msCount_1000=0,msCount_100=0,msCount_10=0,elapsedTime=0;//static修饰的静态局部变量只执行初始化一次
    static double sCurrent_1=0,refPosition_pre=0,refVel_pre=0,refAcc_pre=0;
    double sCurrent,vCurrent,aCurrent;
    double refPosition=0,refVel=0,refAcc=0;
    double uk=0,ukThreeFreedom[DISSENSORCOUNT],series0,series1;

    msCount      += PERFORMANCEINTERVAL;//记录程序运行总时间 ms
    msCount_1000 += PERFORMANCEINTERVAL;//到1000ms清零
    msCount_100  += PERFORMANCEINTERVAL;//到100ms清零
    msCount_10   += PERFORMANCEINTERVAL;//到10ms清零
    elapsedTime  += PERFORMANCEINTERVAL / 1000.0;//程序运行总时间，绘图使用 Unit: s
    //--------------------Read Real Displacement--------------------------
    for(int i=0;i<DISSENSORCOUNT;i++){
         sCurrentThreeFreedom[i]=getPosition(i);
         sCurrentThreeFreedom[i]=sAvgFilterThreeFreedom[i].filter(sCurrentThreeFreedom[i]);
    }
    sCurrent=sCurrentThreeFreedom[0];//与原有程序兼容
    //---------------默认进行静态控制，固定住振动台------------------------------
    if(waveMode==StaticPosionFlag){//静态位移控制,固定采用PID控制方法
        refPosition=0;
        uk=sController->getUk(sCurrent,refPosition);
        outUToPCI(uk);
    }
//----------------------------------------------startFlag=True-------------------------------------------------------------
    if(startFlag){
        msStartCount     += PERFORMANCEINTERVAL;//点击“开始”按钮之后，运行的时间  ms
        msStartCount_Ref += PERFORMANCEINTERVAL;
        elapseStartTime  += PERFORMANCEINTERVAL/1000.0; //   Uint:s
        //--------------------获取Reference------------------------
        if(msStartCount_Ref>=refData.dataRefSampleT){//到一个新的index
            //msStartCount_Ref:采样时间叠加,到5ms清零;refData.dataRefSampleT:参考波形的采样时间
            if(refIndex<=refData.refCnt){
                //----------refIndex---<=refData.refCnt--------
                refPosition=refData.SRef[refIndex];
                refVel=refData.VRef[refIndex];
                refAcc=refData.ARef[refIndex++];
            }
            else {
                refPosition=refVel=refAcc=0;//结束实现为0
                //startFlag=false;//所有数据全部试验结束，停止试验
                on_btnStop_clicked();
            }

            refPosition_pre=refPosition;
            refVel_pre=refVel;
            refAcc_pre=refAcc;

            msStartCount_Ref=0;
        }else{//否则就等于上一次的参考值，为了解决地震波采样周期是5ms的情况--控制周期与参考信号周期不一致
            refPosition=refPosition_pre;
            refVel=refVel_pre;
            refAcc=refAcc_pre;
        }
/*
 * 3个参考值：refPosition、refVel、refAcc
 * 3个实际值：sCurrent、vCurrent、aCurrent
*/
        if (waveMode==SineWaveFlag||waveMode==SineSweepFlag||waveMode==RandomFlag||waveMode==TriangleFlag||waveMode==EarthquakeFlag){
            switch (controlMethod){//枚举控制方法
                case PIDMethod:
                    //uk=sinePIDController->getUk(refPosition,sCurrent);//仅仅采用位移PID控制

                    for(int i=0;i<DISSENSORCOUNT;i++){
                        ukThreeFreedom[i]=sinePIDControllerThreeFreedom[i].getUk(refPosition,sCurrentThreeFreedom[i]);
                    }
                    outUToPCI(ukThreeFreedom);
                    break;
                case ACCPIDMethod:
                    uk=accPIDController->getUk(refAcc,aCurrent);
                    break;
                case Para3Method:
                    uk=tvcController->getUk(TStateInfo(refPosition,refVel,refAcc),TStateInfo(sCurrent,vCurrent,aCurrent));
                    break;
                case PID3Method:
                    uk=pid3Controller->getUk(TStateInfo(refPosition,refVel,refAcc),TStateInfo(sCurrent,vCurrent,aCurrent));
                    break;
                default:break;
            }
            //outUToPCI(uk);
        }
    }
    //--------------10ms将数据存入绘图缓冲区----------------
    if(msCount_10>=10){
        if(dataCnt>MAXDATACOUNT*0.95) dataCnt=0;//防止程序运行时间过程，超出数组长度
        SArray[dataCnt]=sCurrent;//将位移数据存进数组，从0开始计数
        //速度显示平滑滤波
        vCurrent=v2AvgFilter.filter(vCurrent);
        vCurrent=v2ButtorFilter.filter(vCurrent);
        VArray[dataCnt]=vCurrent;

        //aCurrent=a2AvgFilter.filter(aCurrent);
        //aCurrent=a2ButtorFilter.filter(aCurrent);
        AArray[dataCnt]=aCurrent;
        //startFlag==false时，全部为0
        //startFlag==true时，为参考值
        SRefArray[dataCnt]=refPosition;
        VRefArray[dataCnt]=refVel;
        ARefArray[dataCnt++]=refAcc;

        //refPosition=sDisplayBuffer.delay(refPosition);//参考值延迟绘图
        //refVel=vDisplayBuffer.delay(refVel);
        //refAcc=aDisplayBuffer.delay(refAcc);
        if(startFlag){//segData中数据个数：[0,segData.refCnt-1]
            refSegData.SRef[segData.refCnt]=refPosition;
            refSegData.VRef[segData.refCnt]=refVel;
            refSegData.ARef[segData.refCnt]=refAcc;

            segData.SRef[segData.refCnt]=sCurrent;
            segData.VRef[segData.refCnt]=vCurrent;
            segData.ARef[segData.refCnt++]=aCurrent;
            if(segData.refCnt>MAXDATACOUNT*0.95) segData.refCnt=0;//防止程序运行时间过程，超出数组长度
        }

        if(drawType==DisType){//显示实时位移
            //series0=refPosition;series1=sCurrent;
            series0=sCurrentThreeFreedom[0];series1=sCurrentThreeFreedom[1];
            series0=100;series1=1;
        }else if(drawType==VelType){//显示实时速度
            series0=refVel;series1=vCurrent;
        }else{
            series0=refAcc;series1=aCurrent;
        }
        buffer.put(DataPacket(elapsedTime,series0,series1));
        msCount_10=0;
    }
    //--------------------Display-------------------------------------------
    if(msCount_100>=100){//保留三位小数
        ui->lcd_S->display(QString::number(sCurrent,'f',3));
        ui->lcd_V->display(QString::number(vCurrent,'f',3));
        ui->lcd_A->display(QString::number(aCurrent,'f',3));
        msCount_100=0;
        if(startFlag)
            ui->progressBar->setValue(min(refIndex,refData.refCnt));//更新进度条
    }
    //---------------update time in StateBar----------
    if (msCount_1000>=1000){
        QDateTime time = QDateTime::currentDateTime();
        QString str =time.toString("yyyy-MM-dd hh:mm:ss");
        currentLabel->setText(str);
        msCount_1000=0;
    }
}

void MainWindow::on_btnStart_clicked(){
    if(refData.refCnt<500){
        QString mess="未载入数据或者采样点太少，请设置后重新开始";
        QMessageBox::warning(this,"警告",mess,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
        mess="[warning] "+mess;
        addItemToListView(mess);logger->appendLogger(mess);
        return;
    }

    QString log="[info] "+QString("试验开始");
    addItemToListView(log);logger->appendLogger(log);

    ui->tabWidget_pic ->setCurrentIndex(0);//展示绘图页面，而不是预览界面
    //Icon以及Enable变化
    ui->btnStart->setStyleSheet("QPushButton#btnStart{border-image:url(:Icon/Icon/startIconClicked.png)}");
    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(true);
    ui->btnStop->setStyleSheet("QPushButton#btnStop{border-image:url(:Icon/Icon/stopIcon.png)}");
    //在停止按钮里面也做了一次
    sinePIDController->clear();//可能第一次结束，第二次试验
    for(int i=0;i<DISSENSORCOUNT;i++)
        sinePIDControllerThreeFreedom[i].clear();
    accPIDController->clear();
    tvcController->clear();
    pid3Controller->clear();

    msStartCount=msStartCount_Ref=elapseStartTime=0;refIndex=1;
    waveMode=waveModeTmp;
    ui->progressBar->setRange(1,refData.refCnt);//设置进度条
    ui->progressBar->setValue(1);
    startFlag=true;
    //if(!timer->isStart()) timer->start(PERFORMANCEINTERVAL);//定时器已经被关上了
}

void MainWindow::on_btnStop_clicked(){
    if(!startFlag) {
        QString mess="试验尚未开始";
        QMessageBox::warning(this,"警告",mess,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);

        mess="[warning] "+mess;
        addItemToListView(mess);logger->appendLogger(mess);
        return;
    }
    log="[info] "+QString("试验结束");
    addItemToListView(log);logger->appendLogger(log);

    //timer->stop();//停止定时器就不会向buffer中写入数据，进而绘图就停止了
    startFlag=false;
    //此时继续让振动台位置固定
    double scur=getPosition(0);
    sController->configure(0,scur);
    waveMode=StaticPosionFlag;

    outUToPCI(0.0);

    //清空位移PID控制器中累积的Uk_1,ek_1等
    sinePIDController->clear();//可能第一次结束，第二次试验
    for(int i=0;i<DISSENSORCOUNT;i++)
        sinePIDControllerThreeFreedom[i].clear();
    accPIDController->clear();
    tvcController->clear();
    pid3Controller->clear();
    //-----------------StyleSheet-----------------------
    ui->btnStart->setStyleSheet("QPushButton#btnStart{border-image:url(:Icon/Icon/startIcon.png)}");
    ui->btnStart->setEnabled(true);
    ui->btnStop->setStyleSheet("QPushButton#btnStop{border-image:url(:Icon/Icon/stopIconClicked.png)}");

    ui->progressBar->setValue(refData.refCnt);//更新进度条
    double coeff=MathTool::coeff(ydData.ARef,segData.ARef,ydData.refCnt);
    QMessageBox::warning(this,"警告",QString("上轮试验结束，参考信号与实时信号的相关系数是：")+QString::number(coeff),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);

    //采样频率100Hz
    segsData[segCnt].refCnt=segData.refCnt;
    for(int i=0;i<segData.refCnt;i++){
        segsData[segCnt].SRef[i]=segData.SRef[i];
        segsData[segCnt].VRef[i]=segData.VRef[i];
        segsData[segCnt].ARef[i]=segData.ARef[i];
    }
    //频率未定，可能大于100Hz
    refsData[segCnt].refCnt=segData.refCnt;
    for(int i=0;i<refData.refCnt;i++){
        refsData[segCnt].SRef[i]=refSegData.SRef[i];
        refsData[segCnt].VRef[i]=refSegData.VRef[i];
        refsData[segCnt].ARef[i]=refSegData.ARef[i];
    }
    segCnt++;
    segData.refCnt=0;
}

void MainWindow::on_action_Quit_triggered(){
    this->close();
}

void MainWindow::on_action_ToolFlag_triggered(){
    if (ui->action_ToolFlag->isChecked())
        ui->toolBar->setVisible(false);
    else
        ui->toolBar->setVisible(true);
}

void MainWindow::on_action_StatusFlag_triggered(){
    if (ui->action_StatusFlag->isChecked())
        ui->statusBar->setVisible(false);
    else
        ui->statusBar->setVisible(true);
}

void MainWindow::on_action_About_triggered(){
    AboutForm *aboutForm=new AboutForm;
    aboutForm->show();
}

void MainWindow::on_action_HelpF1_triggered(){/*
    QDesktopServices desktopServices;
    QString strUrl=QCoreApplication::applicationDirPath () ;
    strUrl=QString("D:/Popwil/PopWil/Help/VCSHelp.chm").arg (strUrl);
    QUrl qqq(strUrl);
    desktopServices.openUrl(qqq);
    */
}

void MainWindow::on_action_ChannelParameters_triggered(){
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

        log="[info] "+QString("通道参数修改成功");
        addItemToListView(log);logger->appendLogger(log);
    }
}

void MainWindow::on_action_ControlParameters_triggered(){
    CtrlDialog dialog;
    dialog.setPIDParameter();//将参数载入到窗体中
    int resultDialog = dialog.exec();
    if (resultDialog == QDialog::Rejected){
        //exit(0);
    }
    else {
        sinePIDController->setPIDPara(sinePIDInfo);//位移PID参数改变，重新载入控制器
        sinePIDControllerThreeFreedom[0].setPIDPara(pid3Info.dis);
        sinePIDControllerThreeFreedom[1].setPIDPara(pid3Info.vel);
        sinePIDControllerThreeFreedom[2].setPIDPara(pid3Info.acc);
        accPIDController->setPIDPara(accPIDInfo);//加速度PID控制
        tvcController->setTvcPara(tvcInfo);//tvcInfo可能已经修改了，此处需要重新调用
        pid3Controller->setPara(pid3Info);
//        qDebug()<<"PID 参数是:"<<sPIDInfo.SP<<"  "<<sPIDInfo.SI<<"  "<<sPIDInfo.SD;
//        qDebug()<<"sinePID 参数是:"<<sinePIDInfo.SP<<"  "<<sinePIDInfo.SI<<"  "<<sinePIDInfo.SD;
        log="[info] "+QString("控制参数修改成功");
        addItemToListView(log);logger->appendLogger(log);
    }
}

void MainWindow::on_action_SaveAsDefalut_triggered(){
    //------------------------------PCI1716.ini---------------------------------------
    ConfigureParameterPCI tmp;
    tmp.iniSettingAI=configureAI;
    tmp.iniSettingAO=configureAO;
    IniHelper *tmpHelper=new IniHelper;
    QString info;
    bool result=tmpHelper->writeToPCIIni("E://PopWilCacher//IniSetting//PCI1716.ini",tmp);
    if (result)
    {
        info="[info] PCI1716.ini已保存为默认设置！";
    }
    else
        info="[error] PCI1716.ini保存失败";
    qDebug()<<info;
    addItemToListView(info);logger->appendLogger(info);
    //------------------------------CtrlIni.ini---------------------------------------
    result=tmpHelper->writeToCtrlIni("E://PopWilCacher//IniSetting//CtrlIni.ini");
    if (result)
    {
        info="[info] CtrlIni.ini已保存为默认设置！";
    }
    else
        info="[error] CtrlIni.ini保存失败";
    qDebug()<<info;
    addItemToListView(info);logger->appendLogger(info);

    result=tmpHelper->writeToTvcInfo("E://PopWilCacher//IniSetting//TvcInfo.ini");
    if (result){
        info="[info] TvcInfo.ini已保存为默认设置！";
    }
    else info="[error] TvcInfo.ini保存失败";
    qDebug()<<info;
    addItemToListView(info);logger->appendLogger(info);
    //------------------------------SystemInfo.ini---------------------------------------
    result=tmpHelper->writeToSystemInfoIni("E://PopWilCacher//IniSetting//SystemInfo.ini",systemInfo);
    if (result)
    {
        info="[info] SystemInfo.ini已保存为默认设置！";
    }
    else
        info="[error] SystemInfo.ini保存失败";
    qDebug()<<info;
    addItemToListView(info);logger->appendLogger(info);
    delete tmpHelper;
}

void MainWindow::on_action_SystemSettings_triggered(){
    SystemSettings dialog;
    dialog.setSystemInfo();
    int resultDialog = dialog.exec();
    if (resultDialog == QDialog::Rejected){
        //exit(0);
    }
    else if(resultDialog == QDialog::Accepted){
        qDebug()<<"new setted system info is :"<<systemInfo.contrlInterval<<systemInfo.drawInterval;
        log="[info] "+QString("系统参数修改成功");
        addItemToListView(log);logger->appendLogger(log);
    }
}

void MainWindow::addItemToListView(QString str){
    QStandardItem *item = new QStandardItem(str);
    QColor color;
    switch (str.toLatin1().data()[1])
    {
        case 'i':color=QColor(238, 255, 246);//[info]
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

void MainWindow::outUToPCI(double value){
    double MAXOUTU=systemInfo.maxOutU;
    value=value>MAXOUTU?MAXOUTU:value;
    value=value<-MAXOUTU?-MAXOUTU:value;

    aoInstant->outU(value);
}

void MainWindow::outUToPCI(double value[]){
    double MAXOUTU=systemInfo.maxOutU;
    for(int i=0;i<DISSENSORCOUNT;i++){
        value[i]=value[i]>MAXOUTU?MAXOUTU:value[i];
        value[i]=value[i]<-MAXOUTU?-MAXOUTU:value[i];
    }
    aoInstant->outU(value);
}

void MainWindow::on_btn_clearZero_clicked(){
    waveMode=DefaultFlag;//否则进入slotFunction会进入静态控制模式
     Enc7480_Set_Encoder(0,0);
}

void MainWindow::testFunction(){

//    double fft_test[10]={1,3,67,12,2,34,3,1,0,4},out[10][2],out_[10];
//    SignalProcess handler;
//    handler.fft(10,fft_test,out);
//    for(int i=0;i<10;i++)
//        qDebug()<<out[i][0]<<"  "<<out[i][1];

//    handler.ifft(10,out,out_);
//    for(int i=0;i<10;i++)
//        qDebug()<<out_[i];

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

void MainWindow::on_btn_static_comfirm_clicked(){
    double sCurrent=getPosition(0);//这个就是当前的基准电压
    double desPosition=ui->lineEdit_desPosition->text().toDouble();
    double staticControlRestrictDis=systemInfo.maxAbsolutePosition;
    if(fabs(desPosition)>staticControlRestrictDis){
        QMessageBox::warning(this,"警告","目标位置超过振动台量程，位移限幅±"+QString::number(staticControlRestrictDis)+"mm",\
                             QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
        return;
    }
    sController->configure(desPosition,sCurrent);
    waveMode=StaticPosionFlag;
}

void MainWindow::on_btn_DO_clicked(){
    quint8 status;
    if(doInstant->getDoState()){
        ui->btn_DO->setStyleSheet("QPushButton#btn_DO{border-image:url(:Icon/Icon/switch_off.png)}");
        status = 0;
        log=tr("[warning] 驱动已经断开！");
        addItemToListView(log);logger->appendLogger(log);
    }
    else{
        ui->btn_DO->setStyleSheet("QPushButton#btn_DO{border-image:url(:Icon/Icon/switch_on.png)}");
        status=1;
        log=tr("[info] 驱动已连接！");
        addItemToListView(log);logger->appendLogger(log);
    }
    doInstant->setDoState(status);
}

void MainWindow::outDataToExcel(){
    QXlsx::Document xlsx;
    QXlsx::Format centerAlign;
    centerAlign.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    if(xlsx.selectSheet("Sheet1")) xlsx.deleteSheet("Sheet1");
//-----------------Model Sheet-----------------------
    if(!xlsx.selectSheet("Model")) xlsx.addSheet("Model");

    xlsx.setColumnWidth(1,100,15);
    xlsx.write("A1", "频率F",centerAlign);
    xlsx.write("B1","Model_Real",centerAlign);
    xlsx.write("C1","Model_Img",centerAlign);

    int modelCnt=systemModel.Nfft/2+1;
    for (int i=0;i<modelCnt;i++){
       xlsx.write(i+2,1,systemModel.F[i],centerAlign);
       xlsx.write(i+2,2,systemModel.Txy_real[i],centerAlign);
       xlsx.write(i+2,3,systemModel.Txy_imag[i],centerAlign);
    }

    //QXlsx::Chart *lineChart = xlsx.insertChart(3, 8, QSize(900, 300));
    //lineChart->setChartType(QXlsx::Chart::CT_Line);
    //lineChart->addSeries(QXlsx::CellRange("A2:B"+QString::number(count)));
    //-----------------Data Sheet-----------------------
    if(!xlsx.selectSheet("Data")) xlsx.addSheet("Data");
    xlsx.setColumnWidth(1,100,15);
    QXlsx::Format format;
    format.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    format.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    format.setBorderStyle(QXlsx::Format::BorderThin);
    format.setBorderColor(Qt::red);
    format.setFontColor(Qt::blue);

    xlsx.write("A1",QString("参考加速度Yd/g"),centerAlign);
    for(int i=0;i<ydData.refCnt;i++)
        xlsx.write(i+4,1,ydData.ARef[i],centerAlign);

    xlsx.write("B1",QString("全局数据"),centerAlign);
    xlsx.mergeCells("B1:H1",centerAlign);
    xlsx.write("B2","内环参考值",centerAlign);
    xlsx.mergeCells("B2:D2",centerAlign);
    xlsx.write("E2","实时数据",centerAlign);
    xlsx.mergeCells("E2:G2",centerAlign);
    xlsx.write("B3","S/mm",centerAlign);
    xlsx.write("C3","V/mm/s",centerAlign);
    xlsx.write("D3","A/g",centerAlign);
    xlsx.write("E3","S/mm",centerAlign);
    xlsx.write("F3","V/mm/s",centerAlign);
    xlsx.write("G3","A/g",centerAlign);
    xlsx.write("H2","输出电压/V",centerAlign);
    xlsx.mergeCells("H2:H3",centerAlign);
    for(int i=0;i<dataCnt;i++){
        xlsx.write(i+4,2,SRefArray[i],centerAlign);
        xlsx.write(i+4,3,VRefArray[i],centerAlign);
        xlsx.write(i+4,4,ARefArray[i],centerAlign);
        xlsx.write(i+4,5,SArray[i],centerAlign);
        xlsx.write(i+4,6,VArray[i],centerAlign);
        xlsx.write(i+4,7,AArray[i],centerAlign);
        xlsx.write(i+4,8,OutUArray[i],centerAlign);
    }
    for(int i=0;i<segCnt;i++){
        xlsx.write(1,9+7*i,QString("迭代次数："+QString::number(i)),centerAlign);
        xlsx.mergeCells(QXlsx::CellRange(1,9+7*i,1,15+7*i),centerAlign);
        xlsx.write(2,9+7*i,"驱动信号",centerAlign);
        xlsx.mergeCells(QXlsx::CellRange(2,9+7*i,2,11+7*i),centerAlign);
        xlsx.write(2,12+7*i,"实时数据",centerAlign);
        xlsx.mergeCells(QXlsx::CellRange(2,12+7*i,2,14+7*i),centerAlign);

        xlsx.write(3,9+7*i,"S/mm",centerAlign);
        xlsx.write(3,10+7*i,"V/mm/s",centerAlign);
        xlsx.write(3,11+7*i,"A/g",centerAlign);
        xlsx.write(3,12+7*i,"S/mm",centerAlign);
        xlsx.write(3,13+7*i,"V/mm/s",centerAlign);
        xlsx.write(3,14+7*i,"A/g",centerAlign);
        xlsx.write(2,15+7*i,"输出电压/V",centerAlign);
        xlsx.mergeCells(QXlsx::CellRange(2,15+7*i,3,15+7*i),centerAlign);
        qDebug()<<"-----------------"<<refsData[i].refCnt<<"-------"<<segsData[i].refCnt;
        for(int j=0;j<refsData[i].refCnt;j++){
            xlsx.write(j+4,9+7*i,refsData[i].SRef[j],centerAlign);
            xlsx.write(j+4,10+7*i,refsData[i].VRef[j],centerAlign);
            xlsx.write(j+4,11+7*i,refsData[i].ARef[j],centerAlign);
        }
        for(int j=0;j<segsData[i].refCnt;j++){
            xlsx.write(j+4,12+7*i,segsData[i].SRef[j],centerAlign);
            xlsx.write(j+4,13+7*i,segsData[i].VRef[j],centerAlign);
            xlsx.write(j+4,14+7*i,segsData[i].ARef[j],centerAlign);
        }
    }

    QDateTime currentTime = QDateTime::currentDateTime();
    QString current = currentTime.toString("yyyyMMdd_hhmm");
    QString path="E://PopWilCacher//data//"+current+".xlsx";
    qDebug()<<path;
    xlsx.saveAs(path);/*保存*/
    log="[info] 数据保存"+path+"成功";
    addItemToListView(log);logger->appendLogger(log);
}

void MainWindow::dataSaveToTxt(){
    QString message;
    QString path=dataSaveBasePath;
    path += QDateTime::currentDateTime().toString("yyyyMMdd_hhmm");
    path += ".txt";
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        message="[error] 文件"+path+"创建失败";
        addItemToListView(message);logger->appendLogger(message);
        return;
    }

    QTextStream out(&file);
    out.setCodec(QTextCodec::codecForName("UTF-8"));
    message="[info] 文件"+path+"创建成功！";
    addItemToListView(message);logger->appendLogger(message);
    //---------------data---------------
    out<<QString("采样点数： ")<<dataCnt<<endl;
    out<<QString("采样间隔/ms:")<<10<<endl;
    out<<QString("i     参考位移/mm      参考速度/mm/s      参考加速度/g      位移/mm     速度/mm/s     加速度/g")<<endl;
    for(int i=0;i<dataCnt;i++)
         out<<i<<"    "<<SRefArray[i]<<"   "<<VRefArray[i]<<"   "<<ARefArray[i]<<"   "
          <<SArray[i]<<"   "<<VArray[i]<<"   "<<AArray[i]<<endl;

    double coeff_dis=signalHandler.coeff(SArray,SRefArray,dataCnt);
    out<<QString("位移的相关系数是：")<<coeff_dis<<endl;
    double coeff_vel=signalHandler.coeff(VArray,VRefArray,dataCnt);
    out<<QString("速度的相关系数是：")<<coeff_vel<<endl;
    double coeff_acc=signalHandler.coeff(AArray,ARefArray,dataCnt);
    out<<QString("加速度的相关系数是：")<<coeff_acc<<endl;

    message="[info] 实验数据保存成功，位置在"+path;
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
    double position;
    if(ssiEnable==false){//ENC_7480相对式位移采集卡
        int x_position = Enc7480_Get_Encoder(direct);
        //sCurrent=x_position*(-0.0024)-0.012;
        position=x_position*g_dis_k+g_dis_bias;
        return position;
    }else{//SSI采集卡
        double x_position=readSSIData(direct,hPDC1)/1000;
        position=x_position*g_dis_k+g_dis_bias;
        return position-160;
    }
}

void MainWindow::on_btn_out_uk_clicked(){
    waveMode=DefaultFlag;
    double outU=ui->le_uk->text().toDouble();
    double restrictOutU=systemInfo.maxOutUDebug;//调试模式下输出电压限制2V
    if(outU>restrictOutU){
        QMessageBox::warning(this,"警告","输出电压过大，限幅"+QString::number(restrictOutU)+"V",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
        return;
    }
    if(outU<-restrictOutU){
       QMessageBox::warning(this,"警告","输出电压过小，限幅"+QString::number(restrictOutU)+"V",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
       return;
    }
    double outUList[DISSENSORCOUNT]={0};
    outUList[0]=ui->le_uk->text().toDouble();
    outUToPCI(outUList);
}

void MainWindow::on_btn_sine_load_clicked()
{
    double mid    =ui->le_mid->text().toDouble();//中心坐标
    double mag    =ui->le_mag->text().toDouble();//幅值
    double fs     =ui->le_fre->text().toDouble();//频率
    double sineCnt=ui->le_cnt->text().toDouble();//重复次数
    //生成参考波形
    refData.refCnt=0;refData.dataRefSampleT=PERFORMANCEINTERVAL;
    double elapseStartTime=0,sRef,sRef_=0;
    while(true){
        if(elapseStartTime>3+sineCnt/fs) break;
        if(elapseStartTime<=3)
            sRef=mag/(3+1/fs/4)*elapseStartTime*sin(2*PI*fs*elapseStartTime)+mid;
        else sRef=mag*sin(2*PI*fs*elapseStartTime)+mid;
        refData.SRef[++refData.refCnt]=sRef;//SRefArray从1开始计数
        refData.VRef[refData.refCnt]=(sRef-sRef_)/(systemInfo.contrlInterval*1.0/1000);
        sRef_=sRef;
        //qDebug()<<"elapseStartTime:"<<elapseStartTime<<" sRef="<<sRef;
        elapseStartTime += systemInfo.contrlInterval*1.0/1000;
    }
    wavePreview(QString("Sine Wave"));
    Enc7480_Set_Encoder(0,0);
    waveMode=SineWaveFlag;
}

void MainWindow::on_cmb_contr_method_currentIndexChanged(int index)
{
    controlMethod=(TControlMethod)index;
}

void MainWindow::on_tabWidget_controller_currentChanged(int index)
{
    switch (index){
    case 0://静态控只能用PID控制
        ui->cmb_contr_method->setCurrentIndex(0);
        ui->cmb_contr_method->setEnabled(false);
        break;
    case 1:
        ui->listWidget_waveMode->setCurrentRow(0);
    default:
        ui->cmb_contr_method->setEnabled(true);
        ui->cmb_contr_method->setCurrentText(0);
        break;
    }
}

void MainWindow::wavePreview(QString title){
    //---------------------预览绘图-----------------------------------
    //最多预览前10000个点
    int previewCnt;
    previewCnt=refData.refCnt<10000?refData.refCnt:10000;
    double index[10000];

    for(int i=0;i<previewCnt;i++)
        index[i]=i*1.0*refData.dataRefSampleT/1000;
    m_ChartViewer->setGeometry(5, 25, 640, 500);
    XYChart *c = new XYChart(650, 480);//画布大小，包括图标和标题等
    c->setPlotArea(30, 30, c->getWidth() - 41, c->getHeight() - 60, c->linearGradientColor(0, 30, 0,
       c->getHeight() - 50, 0xf0f6ff, 0xa0c0ff), -1, 0xffffff, 0xffffff);
    c->addTitle(title.toLatin1(), "simsun.ttc", 18);
    c->setBackground(0xccccff,0x000000);
    if(ui->rbt_S->isChecked()){
        c->addLineLayer(DoubleArray(refData.SRef+1,previewCnt));//添加y轴数据
        c->addText(5, 5, "S/mm", "timesbi.ttf", 11, 0xff0000);
    }
    if(ui->rbt_V->isChecked()){
        c->addLineLayer(DoubleArray(refData.VRef+1,previewCnt));//添加y轴数据
        c->addText(5, 5, "V/mm/s", "timesbi.ttf", 11, 0xff0000);
    }
    if(ui->rbt_A->isChecked()){
        c->addLineLayer(DoubleArray(refData.ARef+1,previewCnt));//添加y轴数据
        c->addText(5, 5, "A/g", "timesbi.ttf", 11, 0xff0000);
    }
    c->xAxis()->setLabels(DoubleArray(index,previewCnt));//添加x轴数据，有点类似C里的指针操作
    c->addText(630, 450, "t/s", "timesbi.ttf", 11, 0xff0000);
    c->xAxis()->setLabelStep(500);//x轴绘图间隔

    m_ChartViewer->setChart(c);
    delete c;
    m_ChartViewer->show();
}

void MainWindow::drawTmp(QString title, int n, double xlabel[], double data[]){
    m_ChartViewer->setGeometry(5, 25, 640, 500);
    XYChart *c = new XYChart(650, 480);//画布大小，包括图标和标题等
    c->setPlotArea(30, 30, c->getWidth() - 41, c->getHeight() - 60, c->linearGradientColor(0, 30, 0,
       c->getHeight() - 50, 0xf0f6ff, 0xa0c0ff), -1, 0xffffff, 0xffffff);
    c->addTitle(title.toLatin1(), "simsun.ttc", 18);
    c->setBackground(0xccccff,0x000000);


    c->addLineLayer(DoubleArray(data,n));//添加y轴数据
    c->addText(5, 5, "A/g", "timesbi.ttf", 11, 0xff0000);

    c->xAxis()->setLabels(DoubleArray(xlabel,n));//添加x轴数据，有点类似C里的指针操作
    c->addText(630, 450, "t/s", "timesbi.ttf", 11, 0xff0000);
    c->xAxis()->setLabelStep(500);//x轴绘图间隔

    m_ChartViewer->setChart(c);
    delete c;
    m_ChartViewer->show();
}

void MainWindow::on_btn_load_clicked(){
    QString message;
//首先将数组中的所有数据清零
    for(int i=0;i<MAXDATACOUNT;i++){//此处不适用memset，容易出错
        refData.SRef[i]=refData.VRef[i]=refData.ARef[i]=0;
    }
    if(ui->tabWidget_controller->currentIndex()==2){//地震波
        QString earthFileName=ui->cmb_earth->currentText();
        QString earthFilePath="E:\\PopWilCacher\\EarthquakeWave\\"+earthFileName+".txt";
        getEarthquakeWave(earthFilePath);//将地震波数据载入到refData数组中
        ui->lab_earth_sample_Cnt->setText(QString::number(refData.refCnt));
        ui->lab_earth_sample_T->setText(QString::number(refData.dataRefSampleT));
        waveModeTmp=EarthquakeFlag;

        signalHandler.inteFD_All(refData.refCnt,(int)(1000/refData.dataRefSampleT),refData.ARef,&refData);

        message="[info] 地震波数据载入成功";
        addItemToListView(message);logger->appendLogger(message);
        return;
    }
    double mid,mag,fs,sineCnt;

    switch (ui->listWidget_waveMode->currentRow()){
    case 0://正弦波
        mid    =ui->le_mid->text().toDouble();//中心坐标
        mag    =ui->le_mag->text().toDouble();//幅值
        fs     =ui->le_fre->text().toDouble();//频率
        sineCnt=ui->le_cnt->text().toDouble();//重复次数
        oscilator.caculateSine(TSineWaveInfo(mid,mag,fs,sineCnt));
        waveModeTmp=SineWaveFlag;

        message="[info] 正弦波数据载入成功";
        addItemToListView(message);logger->appendLogger(message);
        break;
    case 1://正弦扫频
        oscilator.caculateSineSweep(QString("E://PopWilCacher//SingalGenerator//SineSweepData.txt"));
        waveModeTmp=SineSweepFlag;

        message="[info] 正弦扫频数据载入成功";
        addItemToListView(message);logger->appendLogger(message);
        break;
    case 2://随机波
        mag=ui->le_random->text().toDouble();
        oscilator.caculateRandom(mag);
        waveModeTmp=RandomFlag;

        message="[info] 随机波数据载入成功";
        addItemToListView(message);logger->appendLogger(message);
        break;
    case 3://三角波
        mid    =ui->le_mid_tri->text().toDouble();//中心坐标
        mag    =ui->le_mag_tri->text().toDouble();//幅值
        fs     =ui->le_fre_tri->text().toDouble();//频率
        sineCnt=ui->le_cnt_tri->text().toDouble();//重复次数
        oscilator.caculateTriangle(TSineWaveInfo(mid,mag,fs,sineCnt));
        waveModeTmp=TriangleFlag;

        message="[info] 三角波数据载入成功";
        addItemToListView(message);logger->appendLogger(message);
        break;
    }
}
//预览就是把refData中的最多前10000个数据进行一个预览
void MainWindow:: on_btn_preview_clicked(){
    QString title;
    ui->tabWidget_pic->setCurrentIndex(1);
    if(ui->tabWidget_controller->currentIndex()==2){//地震波
        title=ui->cmb_earth->currentText();
        wavePreview(title);
        return;
    }
    QStringList waveModeString;
    waveModeString<<"Sine Wave"<<"Sine Sweep Wave"<<"Random Wave"<<"Triangle Wave";
    title=waveModeString[ui->listWidget_waveMode->currentRow()];
    wavePreview(title);
}
//ListWidget变化
void MainWindow::on_listWidget_waveMode_currentRowChanged(int currentRow)
{
    QVector<QFrame*> frameVector;
    frameVector<<ui->sineFrame<<ui->sineSwepFrame<<ui->randomFrame<<ui->triangleFrame;
    for(int i=0;i<frameVector.size();i++)
        frameVector[i]->setVisible(false);

    switch(currentRow){
    case 0:
        ui->sineFrame->setParent(ui->waveGenerateframe);
        ui->sineFrame->setGeometry(QRect(80,0,221,270));
        ui->sineFrame->setVisible(true);
        break;
    case 1://正弦扫频
        ui->sineSwepFrame->setParent(ui->waveGenerateframe);
        ui->sineSwepFrame->setGeometry(QRect(80,0,221,270));
        ui->sineSwepFrame->setVisible(true);
        break;
    case 2://随机波
        ui->randomFrame->setParent(ui->waveGenerateframe);
        ui->randomFrame->setGeometry(QRect(80,0,221,270));
        ui->randomFrame->setVisible(true);
        break;
    case 3://三角波
        ui->triangleFrame->setParent(ui->waveGenerateframe);
        ui->triangleFrame->setGeometry(QRect(80,0,221,270));
        ui->triangleFrame->setVisible(true);
        break;
    }
}

void MainWindow::on_btn_sineswep_config_clicked(){
    sineSweepForm.show();
}

void MainWindow::on_btn_sineSweep_open_clicked(){
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Sine Sweep File"), "E:/PopWilCacher/SingalGenerator", tr("Text files (*.txt)"));
    ui->le_sineSweep_filename->setText(fileName);
}
//延迟绘图参数设置
void MainWindow::on_action_DrawDelay_triggered(){
    DisplayBufferForm w;
    w.exec();
    //displayDelay这个全局变量可能已经修改了，此处需要重新载入
    sDisplayBuffer.setDelayCnt(displayDelay.sDelay);
    vDisplayBuffer.setDelayCnt(displayDelay.vDelay);
    aDisplayBuffer.setDelayCnt(displayDelay.aDelay);
}

void MainWindow::on_rbt_S_plot_clicked(){
    drawType=DisType;
}

void MainWindow::on_rbt_V_plot_clicked(){
    drawType=VelType;
}

void MainWindow::on_rbt_A_plot_clicked(){
    drawType=AccType;
}

void MainWindow::on_action_IterativeControl_triggered(){
    iterativeControlUI->show();
}

void MainWindow::on_action_Calibration_triggered()
{
    calibrationDialog->show();
}

void MainWindow::on_action_SaveAsPicture_triggered()
{

}

void MainWindow::on_action_Chinese_triggered(){
    qApp->removeTranslator(englishTranslator);
    //ui->retranslateUi(this);
}

void MainWindow::on_action_English_triggered(){
    qApp->installTranslator(englishTranslator);
    //ui->retranslateUi(this);
}

void MainWindow::changeEvent(QEvent *event){
    if(event -> type() == QEvent::LanguageChange){
        ui->retranslateUi(this); 
        refreshUI();
    }
}

void MainWindow::refreshUI(){
    ui->btnStart->setToolTip(tr("开始"));
    ui->btnStart->setMask(QRegion(0,0,50,50,QRegion::Ellipse));
    ui->btnStop->setToolTip(tr("停止"));
    ui->btnStop->setMask(QRegion(0,0,50,50,QRegion::Ellipse));
    ui->btn_DO->setToolTip(tr("开关"));
    ui->btn_load->setToolTip(tr("载入数据"));

    //问题：model之前的数据如何更改?

//    QStandardItemModel *t=new QStandardItemModel(ui->listView_eventInformation);
//    int rows=model->rowCount();
//    for(int i=0;i<rows;i++){
//        QStandardItem *item=model->item(i);
//        t->appendRow(item);
//    }
//    model->clear();
//    for(int i=0;i<rows;i++){
//        QStandardItem *item=t->item(i);
//        model->appendRow(item);
//    }
//    ui->btn_for_languge_test->setText(QString::number(model->rowCount()));
    map<QString,QString> m;
    m["[info] 通道参数文件载入成功！"]=tr("[info] 通道参数文件载入成功！");
    m["[info] PID控制参数文件载入成功！"]=tr("[info] PID控制参数文件载入成功！");
    m["[info] 三参量控制参数文件载入成功！"]=tr("[info] 三参量控制参数文件载入成功！");
    m["[info] 系统参数文件载入成功 "]=tr("[info] 系统参数文件载入成功 ");
    m["初始化ENC7480计数卡失败!"]=tr("初始化ENC7480计数卡失败!");
    m["[error] 初始化ENC7480计数卡失败！"]=tr("[error] 初始化ENC7480计数卡失败！");
    m["[info] 初始化ENC7480计数卡成功！"]=tr("[info] 初始化ENC7480计数卡成功！");
    m["[error] 无法找到PCI设备！"]=tr("[error] 无法找到PCI设备！");
    m["[info] 初始化PCI-1716设备成功！"]=tr("[info] 初始化PCI-1716设备成功！");
    m["[info] 驱动已连接！"]=tr("[info] 驱动已连接！");
    m["[warning] 驱动断开，请重新连接驱动！"]=tr("[warning] 驱动断开，请重新连接驱动！");
    m["[warning] 驱动已经断开！"]=tr("[warning] 驱动已经断开！");


    m["[info] channel parameters load sucess!"]="[info] 通道参数文件载入成功！";
    for(int i=0;i<model->rowCount();i++){
            QStandardItem *item=model->item(i);
            if(m.find(item->text())!=m.end()){
                item->setText(m[item->text()]);
            }
        }
    ui->listView_eventInformation->setModel(model);
    ui->listView_eventInformation->scrollToBottom();
}

void MainWindow::on_btn_out_uk_2_clicked(){
    waveMode=DefaultFlag;
    double outU=ui->le_uk->text().toDouble();
    double restrictOutU=systemInfo.maxOutUDebug;//调试模式下输出电压限制2V
    if(outU>restrictOutU){
        QMessageBox::warning(this,"警告","输出电压过大，限幅"+QString::number(restrictOutU)+"V",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
        return;
    }
    if(outU<-restrictOutU){
       QMessageBox::warning(this,"警告","输出电压过小，限幅"+QString::number(restrictOutU)+"V",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
       return;
    }
    double outUList[DISSENSORCOUNT]={0};
    outUList[1]=ui->le_uk_2->text().toDouble();
    outUToPCI(outUList);
}

void MainWindow::on_btn_out_uk_3_clicked(){
    waveMode=DefaultFlag;
    double outU=ui->le_uk->text().toDouble();
    double restrictOutU=systemInfo.maxOutUDebug;//调试模式下输出电压限制2V
    if(outU>restrictOutU){
        QMessageBox::warning(this,"警告","输出电压过大，限幅"+QString::number(restrictOutU)+"V",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
        return;
    }
    if(outU<-restrictOutU){
       QMessageBox::warning(this,"警告","输出电压过小，限幅"+QString::number(restrictOutU)+"V",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
       return;
    }
    double outUList[DISSENSORCOUNT]={0};
    outUList[2]=ui->le_uk_3->text().toDouble();
    outUToPCI(outUList);
}

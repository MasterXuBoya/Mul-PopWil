#include "IterativeControlMainWindow.h"
#include "ui_IterativeControlMainWindow.h"
//！！！ 注意读入文件加速度数据的列数，此处都是读取时间-加速度数据，加速度位移第二列。。。。。。
//此处可以对于任意地波形进行任意地Resample处理，利用earthquakeInterpolation.ARef仅仅是为了方便
double interpolationIndex[50000];
TRefData earthquakeInterpolation,InterpolationOut;//插值算法读入地震波，和插值后地震波
IterativeControlMainWindow::IterativeControlMainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::IterativeControlMainWindow){

    ui->setupUi(this);
    //ui->tabWidget->removeTab(0);//隐藏某一个tab
    for(int i=0;i<MAXDATACOUNT;i++){
        earthquakeTmpData.ARef[i]=earthquakeTmpData.VRef[i]=earthquakeTmpData.SRef[i]=0;
    }
    earthquakeTmpData.refCnt=0;
    earthquakeTmpData.dataRefSampleT=1;
    //--------------------------QTableView-------------------------------------
    accModel=new QStandardItemModel;
    velModel=new QStandardItemModel;
    disModel=new QStandardItemModel;

    ui->tableView_Acc->setModel(accModel);
    ui->tableView_Vel->setModel(velModel);
    ui->tableView_Dis->setModel(disModel);

    accModel->setColumnCount(2);
    velModel->setColumnCount(2);
    disModel->setColumnCount(2);

    //设置表头
    accModel->setHorizontalHeaderItem(0,new QStandardItem("时间/s"));
    accModel->setHorizontalHeaderItem(1,new QStandardItem("加速度/g"));
    velModel->setHorizontalHeaderItem(0,new QStandardItem("时间/s"));
    velModel->setHorizontalHeaderItem(1,new QStandardItem("速度/mm/s"));
    disModel->setHorizontalHeaderItem(0,new QStandardItem("时间/s"));
    disModel->setHorizontalHeaderItem(1,new QStandardItem("位移/mm"));
    //--------------------------绘图-------------------------------------
    m_acc=new QChartViewer(ui->frame_Acc);
    m_vel=new QChartViewer(ui->frame_Vel);
    m_dis=new QChartViewer(ui->frame_Dis);

    m_Acc_Interpolation=new QChartViewer(ui->frame_Acc_2);
    ui->tabWidget->setCurrentIndex(2);
}

IterativeControlMainWindow::~IterativeControlMainWindow(){
    delete accModel;
    delete velModel;
    delete disModel;

    delete m_acc;
    delete m_vel;
    delete m_dis;
    delete m_Acc_Interpolation;

    delete ui;
}

void IterativeControlMainWindow::on_btn_open_clicked(){
    QString path = QFileDialog::getOpenFileName(this,
        tr("打开地震波文件"), "E:/PopWilCacher/EarthquakeWave", tr("Text files (*.dat)"));
    ui->lineEdit ->setText(path);

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"地震波文件"+path+"文件打开失败";
        QMessageBox::warning(this,"提示","地震波文件打开失败",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
        return;
    }
    qDebug()<<"地震波文件"+path+"打开成功！";

    int cnt=0;
    QTextStream in(&file);
    while (!in.atEnd()) {
        cnt++;
        QString line = in.readLine();
        line=line.trimmed();//去掉两端空格
        line=line.simplified();//将连续的空格转化成一个
        QStringList lines=line.split(" ");//分割
        if(cnt==1){
            earthquakeTmpData.dataRefSampleT=lines[1].toInt();
            continue;
        }
        if(cnt==2) continue;
        int i=cnt-3;//从0开始编号
        earthquakeTmpData.ARef[i]=lines[1].toDouble();//.dat文件，此处只有两列
    }
    earthquakeTmpData.refCnt=cnt-2;
    qDebug()<<"earthquake cnt="<<earthquakeTmpData.refCnt<<"earthquake sampleT="<<earthquakeTmpData.dataRefSampleT;
    //直接频域积分的方法
    //signalHanler.inteFD_All(earthquakeTmpData.refCnt,(int)(1000/earthquakeTmpData.dataRefSampleT),earthquakeTmpData.ARef,&earthquakeTmpData);
    //调用MATLAB提供的接口函数，earthquakeTmpData.ARef从0开始编号，mwArray从1开始编号
    mwArray accData(1,earthquakeTmpData.refCnt,mxDOUBLE_CLASS);
    accData.SetData(earthquakeTmpData.ARef,earthquakeTmpData.refCnt);
    mwArray Fs(1,1,mxDOUBLE_CLASS);
    double FsArray[]={1000/earthquakeTmpData.dataRefSampleT};
    Fs.SetData(FsArray,1);
    mwArray corr_a,corr_v,corr_s;
    matlabHandler.earthPreprocess(3,corr_a,corr_v,corr_s,accData,Fs);
    for(int i=1;i<=earthquakeTmpData.refCnt;i++){
        earthquakeTmpData.ARef[i-1]=corr_a(1,i);
        earthquakeTmpData.VRef[i-1]=corr_v(1,i);
        earthquakeTmpData.SRef[i-1]=corr_s(1,i);
    }

    tableViewShow();
    draw();
}

void IterativeControlMainWindow::tableViewShow(){
    for(int i=0;i<earthquakeTmpData.refCnt;i++){
        accModel->setItem(i,0,new QStandardItem(QString::number(i*earthquakeTmpData.dataRefSampleT/1000.0,'f',2)));
        accModel->setItem(i,1,new QStandardItem(QString::number(earthquakeTmpData.ARef[i],'f',4)));
        velModel->setItem(i,0,new QStandardItem(QString::number(i*earthquakeTmpData.dataRefSampleT/1000.0,'f',2)));
        velModel->setItem(i,1,new QStandardItem(QString::number(earthquakeTmpData.VRef[i],'f',4)));
        disModel->setItem(i,0,new QStandardItem(QString::number(i*earthquakeTmpData.dataRefSampleT/1000.0,'f',2)));
        disModel->setItem(i,1,new QStandardItem(QString::number(earthquakeTmpData.SRef[i],'f',4)));
    }
}

void IterativeControlMainWindow::draw(){
    int baseWitdth=ui->frame_Acc->width();
    int baseHeight=ui->frame_Acc->height();
    double index[10000];
    for(int i=0;i<=earthquakeTmpData.refCnt;i++)
        index[i]=earthquakeTmpData.dataRefSampleT/1000.0*i;

    m_acc->setGeometry(5, 5, baseWitdth-10, baseHeight-10);
    XYChart *c = new XYChart(baseWitdth-10, baseHeight-10);//画布大小，包括图标和标题等
    c->setPlotArea(30, 30, c->getWidth() - 41, c->getHeight() - 60, 0xffffff, -1, 0xffffff,  c->dashLineColor(0x888888, Chart::DotLine), -1);
    //c->addTitle("加速度", "arial.ttf", 18);
    c->setBackground(0xe6f0fa,0x000000);

    c->addLineLayer(DoubleArray(earthquakeTmpData.ARef,earthquakeTmpData.refCnt),0x0000FF);//添加y轴数据和线条颜色
    c->addText(5, 5, "A/g", "timesbi.ttf", 11, 0x000080);

    c->xAxis()->setLabels(DoubleArray(index,earthquakeTmpData.refCnt));//添加x轴数据，有点类似C里的指针操作
    c->addText(baseWitdth-30,baseHeight-35, "t/s", "timesbi.ttf", 11, 0x000080);
    c->xAxis()->setLabelStep(500);//x轴绘图间隔

    m_acc->setChart(c);
    delete c;
    m_acc->show();
    //--------------------------------------------------------------------
    m_vel->setGeometry(5, 5, baseWitdth-10, baseHeight-10);
    c = new XYChart(baseWitdth-10, baseHeight-10);//画布大小，包括图标和标题等
    c->setPlotArea(30, 30, c->getWidth() - 41, c->getHeight() - 60, 0xffffff, -1, 0xffffff,  c->dashLineColor(0x888888, Chart::DotLine), -1);
    c->setBackground(0xe6f0fa,0x000000);

    c->addLineLayer(DoubleArray(earthquakeTmpData.VRef,earthquakeTmpData.refCnt),0x0000FF);//添加y轴数据和线条颜色
    c->addText(5, 5, "V/mm/s", "timesbi.ttf", 11, 0x000080);

    c->xAxis()->setLabels(DoubleArray(index,earthquakeTmpData.refCnt));//添加x轴数据，有点类似C里的指针操作
    c->addText(baseWitdth-30,baseHeight-35, "t/s", "timesbi.ttf", 11, 0x000080);
    c->xAxis()->setLabelStep(500);//x轴绘图间隔

    m_vel->setChart(c);
    delete c;
    m_vel->show();
    //-----------------------------------------------------------------------
    m_dis->setGeometry(5, 5, baseWitdth-10, baseHeight-10);
    c = new XYChart(baseWitdth-10, baseHeight-10);//画布大小，包括图标和标题等
    c->setPlotArea(30, 30, c->getWidth() - 41, c->getHeight() - 60, 0xffffff, -1, 0xffffff,c->dashLineColor(0x888888, Chart::DotLine), -1);
    c->setBackground(0xe6f0fa,0x000000);

    c->addLineLayer(DoubleArray(earthquakeTmpData.SRef,earthquakeTmpData.refCnt),0x0000FF);//添加y轴数据和线条颜色
    c->addText(5, 5, "S/mm", "timesbi.ttf", 11, 0x000080);

    c->xAxis()->setLabels(DoubleArray(index,earthquakeTmpData.refCnt));//添加x轴数据，有点类似C里的指针操作
    c->addText(baseWitdth-30,baseHeight-35, "t/s", "timesbi.ttf", 11, 0x000080);
    c->xAxis()->setLabelStep(500);//x轴绘图间隔

    m_dis->setChart(c);
    delete c;
    m_dis->show();
}

void IterativeControlMainWindow::paintEvent(QPaintEvent *event){
    draw();
}

void IterativeControlMainWindow::on_btn_open_2_clicked(){
    QString path = QFileDialog::getOpenFileName(this,
        tr("打开地震波文件"), "E:/PopWilCacher/EarthquakeWave", tr("Text files (*.dat)"));
    ui->lineEdit_2 ->setText(path);

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"地震波文件"+path+"文件打开失败";
        return;
    }
    qDebug()<<"地震波文件"+path+"打开成功！";

    int cnt=0;
    QTextStream in(&file);
    while (!in.atEnd()) {
        cnt++;
        QString line = in.readLine();
        line=line.trimmed();//去掉两端空格
        line=line.simplified();//将连续的空格转化成一个
        QStringList lines=line.split(" ");//分割
        if(cnt==1){
            earthquakeInterpolation.dataRefSampleT=lines[1].toInt();
            continue;
        }
        if(cnt==2) continue;
        int i=cnt-3;//从0开始编号
        earthquakeInterpolation.ARef[i]=lines[1].toDouble();//此处只有两列
    }
    earthquakeInterpolation.refCnt=cnt-2;
    ui->lab_origin_sampleT->setText(QString::number(earthquakeInterpolation.dataRefSampleT));
    ui->lab_origin_cnt->setText(QString::number(earthquakeInterpolation.refCnt));

    for(int i=0;i<=earthquakeInterpolation.refCnt;i++)
        interpolationIndex[i]=earthquakeInterpolation.dataRefSampleT/1000.0*i;

    int baseWitdth=ui->frame_Acc_2->width();
    int baseHeight=ui->frame_Acc_2->height();

    m_Acc_Interpolation->setGeometry(5, 5, baseWitdth-10, baseHeight-10);
    XYChart *c = new XYChart(baseWitdth-10, baseHeight-10);//画布大小，包括图标和标题等
    c->setPlotArea(30, 30, c->getWidth() - 41, c->getHeight() - 60, 0xffffff, -1, 0xffffff,  c->dashLineColor(0x888888, Chart::DotLine), -1);
    //c->addTitle("加速度", "arial.ttf", 18);
    c->setBackground(0xe6f0fa,0x000000);

    c->addLineLayer(DoubleArray(earthquakeInterpolation.ARef,earthquakeInterpolation.refCnt),0x0000FF);//添加y轴数据和线条颜色
    c->addText(5, 5, "A/g", "timesbi.ttf", 11, 0x000080);

    c->xAxis()->setLabels(DoubleArray(interpolationIndex,earthquakeInterpolation.refCnt));//添加x轴数据，有点类似C里的指针操作
    c->addText(baseWitdth-30,baseHeight-35, "t/s", "timesbi.ttf", 11, 0x000080);
    c->xAxis()->setLabelStep(500);//x轴绘图间隔

    m_Acc_Interpolation->setChart(c);
    delete c;
    m_Acc_Interpolation->show();
}

void IterativeControlMainWindow::on_btn_save_clicked(){
    QString path=QFileDialog::getSaveFileName(this,tr("保存地震波数据"),"E:/PopWilCacher/EarthquakeWave",tr("Text files (*.txt *.dat)"));

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug()<<"保存地震波文件"+path+"文件打开失败";
        QMessageBox::warning(this,"提示","保存路径打开失败",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
        return;
    }
    qDebug()<<"保存地震波文件"+path+"打开成功！";
    QTextStream out(&file);
    out<<QString("时间间隔(ms)")<<"        "<<earthquakeTmpData.dataRefSampleT<<endl;
    out<<QString("试验点位移<mm>   速度<mm/s>   加速度<g>")<<endl;
    for(int i=0;i<earthquakeTmpData.refCnt;i++)
        out<<i<<"     "<<QString::number(earthquakeTmpData.SRef[i],'f',5)<<"     "
                       <<QString::number(earthquakeTmpData.VRef[i],'f',5)<<"     "
                       <<QString::number(earthquakeTmpData.ARef[i],'f',5)<<endl;
    QString mess="地震波文件"+path+"保存成功！";
    qDebug()<<mess;
    QMessageBox::warning(this,"提示",mess,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
}

void IterativeControlMainWindow::on_btn_resample_clicked(){
    if(ui->le_new_sample->text()==""){
        QMessageBox::warning(this,"警告","请输入新的采样周期重试",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
        return;
    }
    //四点法插值，只能往点数多的方向插值
//    signalHanler.lagrangeInterpolation(earthquakeInterpolation.refCnt,
//                                       earthquakeInterpolation.dataRefSampleT,
//                                       earthquakeInterpolation.ARef,
//                                       &InterpolationOut,
//                                       2);

    mwArray accData(1,earthquakeInterpolation.refCnt,mxDOUBLE_CLASS);
    accData.SetData(earthquakeInterpolation.ARef,earthquakeInterpolation.refCnt);

    mwArray oldFs(1,1,mxDOUBLE_CLASS);
    double oldFsArray[]={1000/earthquakeInterpolation.dataRefSampleT};
    oldFs.SetData(oldFsArray,1);
    mwArray newFs(1,1,mxDOUBLE_CLASS);
    InterpolationOut.dataRefSampleT=ui->le_new_sample->text().toInt();
    double newFsArray[]={1000/InterpolationOut.dataRefSampleT};
    newFs.SetData(newFsArray,1);

    mwArray newSampleData;
    matlabHandler.waveSample(1,newSampleData,accData,newFs,oldFs);
    InterpolationOut.refCnt=newSampleData.NumberOfElements();
    for(int i=1;i<=InterpolationOut.refCnt;i++){
        InterpolationOut.ARef[i-1]=newSampleData(1,i);
    }

    qDebug()<<"插值后数据="<<InterpolationOut.refCnt;


    ui->lab_new_cnt->setText(QString::number(InterpolationOut.refCnt));

    int baseWitdth=ui->frame_Acc_2->width();
    int baseHeight=ui->frame_Acc_2->height();

    for(int i=0;i<=InterpolationOut.refCnt;i++)
        interpolationIndex[i]=InterpolationOut.dataRefSampleT/1000.0*i;

    m_Acc_Interpolation->setGeometry(5, 5, baseWitdth-10, baseHeight-10);
    XYChart *c = new XYChart(baseWitdth-10, baseHeight-10);//画布大小，包括图标和标题等
    c->setPlotArea(30, 30, c->getWidth() - 41, c->getHeight() - 60, 0xffffff, -1, 0xffffff,  c->dashLineColor(0x888888, Chart::DotLine), -1);
    //c->addTitle("加速度", "arial.ttf", 18);
    c->setBackground(0xe6f0fa,0x000000);

    c->addLineLayer(DoubleArray(InterpolationOut.ARef,InterpolationOut.refCnt),0x0000FF);//添加y轴数据和线条颜色
    c->addText(5, 5, "A/g", "timesbi.ttf", 11, 0x000080);

    c->xAxis()->setLabels(DoubleArray(interpolationIndex,InterpolationOut.refCnt));//添加x轴数据，有点类似C里的指针操作
    c->addText(baseWitdth-30,baseHeight-35, "t/s", "timesbi.ttf", 11, 0x000080);
    c->xAxis()->setLabelStep(500);//x轴绘图间隔

    m_Acc_Interpolation->setChart(c);
    delete c;
    m_Acc_Interpolation->show();
}

void IterativeControlMainWindow::on_btn_resample_save_clicked(){
    QString path=QFileDialog::getSaveFileName(this,tr("保存插值后数据"),"E:/PopWilCacher/EarthquakeWave",tr("Text files (*.txt *.dat)"));

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug()<<"插值数据文件"+path+"文件打开失败";
        QMessageBox::warning(this,"提示","保存路径打开失败",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
        return;
    }
    qDebug()<<"保存插值数据文件"+path+"打开成功！";
    QTextStream out(&file);
    out<<QString("时间间隔(ms)")<<"        "<<InterpolationOut.dataRefSampleT<<endl;
    out<<QString("试验点位移<mm>   速度<mm/s>   加速度<g>")<<endl;
    for(int i=0;i<InterpolationOut.refCnt;i++)
        out<<i<<"     "<<QString::number(InterpolationOut.ARef[i],'f',5)<<endl;
    QString mess="插值数据"+path+"保存成功！";
    qDebug()<<mess;
    QMessageBox::warning(this,"提示",mess,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
}
//将固定的扫频信号载入到refData
void IterativeControlMainWindow::on_pushButton_clicked(){
    QString path = QFileDialog::getOpenFileName(this,
        tr("打开扫频激励信号文件"), "E:/PopWilCacher/SingalGenerator", tr("Text files (*.txt)"));

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"扫频文件"+path+"文件打开失败";
        QMessageBox::warning(this,"提示","地震波文件打开失败",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
        return;
    }

    int cnt=0;//refData从0开始编号
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        line=line.trimmed();//去掉两端空格
        line=line.simplified();//将连续的空格转化成一个
        QStringList lines=line.split(" ");//分割
        refData.ARef[cnt]=lines[0].toDouble();//.dat文件，此处只有两列
        if(lines.size()>1){
            refData.VRef[cnt]=lines[1].toDouble();//.dat文件，此处只有两列
            refData.SRef[cnt]=lines[2].toDouble();//.dat文件，此处只有两列
        }
        cnt++;
    }
    refData.refCnt=cnt;
    refData.dataRefSampleT=10;
    waveModeTmp=SineWaveFlag;
}
/**
 * 激励信号保存在refData中，数据长度refData.refCnt
 * 响应信号保存在segData中，数据长度相同refData.refCnt
 * void transformFunction(int nargout, mwArray& Txy, mwArray& F, const mwArray& x, const mwArray& y, const mwArray& nfft, const mwArray& fs);
 */
void IterativeControlMainWindow::on_pushButton_3_clicked(){
    //x:refData.ARef
    //y:segData.ARef
    mwArray x(1,refData.refCnt,mxDOUBLE_CLASS);
    x.SetData(refData.ARef,refData.refCnt);
    //_______for Test__________
//    int avgLen=10;
//    for(int i=0;i<=refData.refCnt;i++){
//        if(i<avgLen) segData.ARef[i]=refData.ARef[i];
//        else {
//            double s=0;
//            for(int j=i-avgLen+1;j<=i;j++) s+=refData.ARef[j];
//            segData.ARef[i]=s/avgLen;
//        }
//    }
    mwArray y(1,refData.refCnt,mxDOUBLE_CLASS);
    y.SetData(segData.ARef,refData.refCnt);

    mwArray Nfft(1,1,mxDOUBLE_CLASS);
    int nfft=ui->le_nfft->text().toInt();
    int cnt=1+nfft/2;
    double nfftArray[]={nfft};
    Nfft.SetData(nfftArray,1);

    mwArray Fs(1,1,mxDOUBLE_CLASS);
    int fs=100;
    double FsArray[]={fs};
    Fs.SetData(FsArray,1);

    mwArray Txy,F;//Txy的数据类型是复数mwArray Txy(row,column,Double,Complex)
    matlabHandler.transformFunction(2,Txy,F,x,y,Nfft,Fs);
    //save to global varibale systemModel
    systemModel.Nfft=nfft;
    systemModel.Fs=fs;
    qDebug()<<"------------------------------------"<<(int)Txy.NumberOfElements();
    qDebug()<<"------------------------------------"<<(int)Txy.NumberOfDimensions();

    for(int i=1;i<=cnt;i++){
        systemModel.Txy_real[i-1]=Txy.Real()(i,1);
        systemModel.Txy_imag[i-1]=Txy.Imag()(i,1);
        systemModel.F[i-1]=F(i,1);
    }
}
//设置界面大小
void IterativeControlMainWindow::on_tabWidget_currentChanged(int index){
    if(index>1) setFixedSize(720, 520);
    else setFixedSize(1300,800);
}

void IterativeControlMainWindow::on_btn_model_save_clicked(){
    int cnt=systemModel.Nfft/2+1;//Nfft一定是个偶数

    QString path=QFileDialog::getSaveFileName(this,tr("保存系统模型"),"E:/PopWilCacher/IterationController",tr("Text files (*.txt *.dat)"));
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug()<<"保存系统模型文件"+path+"文件打开失败";
        QMessageBox::warning(this,"提示","保存路径打开失败",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
        return;
    }
    qDebug()<<"保存系统模型文件"+path+"打开成功！";

    QTextStream out(&file);
    out<<QString("谱线数")<<"        "<<systemModel.Nfft<<endl;
    out<<QString("采样频率")<<"        "<<systemModel.Fs<<endl;
    for(int i=0;i<cnt;i++)
        out<<QString::number(systemModel.Txy_real[i],'f',5)<<"     "
           <<QString::number(systemModel.Txy_imag[i],'f',5)<<"     "
           <<QString::number(systemModel.F[i],'f',5)<<endl;
    QString mess="系统模型文件"+path+"保存成功！";
    qDebug()<<mess;
    QMessageBox::warning(this,"提示",mess,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
}

void IterativeControlMainWindow::on_pushButton_2_clicked(){
    QString mess="响应信号已读取";
    QMessageBox::warning(this,"提示",mess,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
}
//读入外环参考加速度信号到ydData
void IterativeControlMainWindow::on_btn_load_yd_clicked(){
    QString path = QFileDialog::getOpenFileName(this,
        tr("打开地震波文件"), "E:/PopWilCacher/EarthquakeWave", tr("Text files (*.dat)"));

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"地震波文件"+path+"文件打开失败";
        QMessageBox::warning(this,"提示","地震波文件打开失败",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
        return;
    }

    int cnt=0;//ydData从0开始编号
    QTextStream in(&file);
    while (!in.atEnd()) {
        cnt++;

        QString line = in.readLine();
        line=line.trimmed();//去掉两端空格
        line=line.simplified();//将连续的空格转化成一个
        QStringList lines=line.split(" ");//分割
        if(cnt==1){
            ydData.dataRefSampleT=lines[1].toInt();
            continue;
        }
        if(cnt==2) continue;
        int i=cnt-3;
        ydData.ARef[i]=lines[1].toDouble();//.dat文件，此处只有两列
        if(lines.size()>2){
            ydData.VRef[i]=lines[2].toDouble();//.dat文件，此处只有两列
            ydData.SRef[i]=lines[3].toDouble();//.dat文件，此处只有两列
        }
    }
    ydData.refCnt=cnt-2;
}

void IterativeControlMainWindow::on_btn_load_model_clicked(){
    //systemModel中已经有系统模型数据，不需要从外部导入
    qDebug()<<"systemModel.nfft="<<systemModel.Nfft;
    if(systemModel.Nfft!=0) {
        QString mess="响应信号已存在";
        QMessageBox::warning(this,"提示",mess,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
        return;
    }
    QString path ="E:/PopWilCacher/IterationController/SystemModel.txt";

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"模型文件"+path+"打开失败";
        QMessageBox::warning(this,"提示","系统模型文件打开失败",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
        return;
    }
    int cnt=0;
    QTextStream in(&file);
    while (!in.atEnd()) {
        cnt++;

        QString line = in.readLine();
        line=line.trimmed();//去掉两端空格
        line=line.simplified();//将连续的空格转化成一个
        QStringList lines=line.split(" ");//分割
        if(cnt==1){
            systemModel.Nfft=lines[1].toInt();
            continue;
        }
        if(cnt==2) {
            systemModel.Fs=lines[1].toInt();
            continue;
        }
        int i=cnt-3;
        systemModel.Txy_real[i]=lines[0].toDouble();
        systemModel.Txy_imag[i]=lines[1].toDouble();
        systemModel.F[i]=lines[2].toDouble();
    }

    QString mess="频响函数读取成功";
    QMessageBox::warning(this,"提示",mess,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
}
//直通模式
void IterativeControlMainWindow::on_btn_cal_drive_clicked(){
    /**
     * yd:ydData
     * Txy,F:systemModel.Txy_real,systemModel.Txy_imag,systemModel.F
     * Nfft:systemModel.Nfft
     * Fs:systemModel.Fs
     */
    mwArray Nfft(1,1,mxDOUBLE_CLASS);
    int nfft=systemModel.Nfft;
    int cnt=1+nfft/2;
    double nfftArray[]={nfft};
    Nfft.SetData(nfftArray,1);

    mwArray Fs(1,1,mxDOUBLE_CLASS);
    int fs=100;
    double FsArray[]={fs};
    Fs.SetData(FsArray,1);

    mwArray Txy(cnt,1,mxDOUBLE_CLASS,mxCOMPLEX);
    Txy.Real().SetData(systemModel.Txy_real,cnt);
    Txy.Imag().SetData(systemModel.Txy_imag,cnt);

    mwArray F(cnt,1,mxDOUBLE_CLASS);
    F.SetData(systemModel.F,cnt);

    mwArray yd(1,ydData.refCnt,mxDOUBLE_CLASS);
    yd.SetData(ydData.ARef,ydData.refCnt);

    mwArray newX;
    matlabHandler.generateFirstDrive(1,newX,Txy,F,yd,Nfft,Fs);

    refData.refCnt=ydData.refCnt;
    refData.dataRefSampleT=10;
    for(int i=0;i<ydData.refCnt;i++){
        refData.ARef[i]=newX(1,i+1);
        refData.VRef[i]=refData.SRef[i]=0;
    }
    //此处点击主页面"预览"按钮可进行加速度预览
    waveModeTmp=SineWaveFlag;
}
/**迭代模式
 * yd:ydData
 * Txy,F:systemModel.Txy_real,systemModel.Txy_imag,systemModel.F
 * Nfft:systemModel.Nfft
 * Fs:systemModel.Fs
 * y:segData.ARef
 * X:refData.ARef
 */
void IterativeControlMainWindow::on_btn_fresh_clicked(){
    iterationIndex++;
    ui->le_iterattion_cnt->setText(QString::number(ui->le_iterattion_cnt->text().toInt()+1));

    //_______for Test__________
//    int avgLen=10;
//    for(int i=0;i<=refData.refCnt;i++){
//        if(i<avgLen) segData.ARef[i]=refData.ARef[i];
//        else {
//            double s=0;
//            for(int j=i-avgLen+1;j<=i;j++) s+=refData.ARef[j];
//            segData.ARef[i]=s/avgLen;
//        }
//    }


    mwArray Nfft(1,1,mxDOUBLE_CLASS);
    int nfft=systemModel.Nfft;
    int cnt=1+nfft/2;
    double nfftArray[]={nfft};
    Nfft.SetData(nfftArray,1);

    mwArray Fs(1,1,mxDOUBLE_CLASS);
    int fs=100;
    double FsArray[]={fs};
    Fs.SetData(FsArray,1);

    mwArray Alpha(1,1,mxDOUBLE_CLASS);
    double alpha=ui->le_learning_rate->text().toDouble();
    double AlphaArray[]={alpha};
    Alpha.SetData(AlphaArray,1);

    mwArray Txy(cnt,1,mxDOUBLE_CLASS,mxCOMPLEX);
    Txy.Real().SetData(systemModel.Txy_real,cnt);
    Txy.Imag().SetData(systemModel.Txy_imag,cnt);

    mwArray F(cnt,1,mxDOUBLE_CLASS);
    F.SetData(systemModel.F,cnt);

    mwArray yd(1,ydData.refCnt,mxDOUBLE_CLASS);
    yd.SetData(ydData.ARef,ydData.refCnt);

    mwArray y(1,ydData.refCnt,mxDOUBLE_CLASS);
    y.SetData(segData.ARef,ydData.refCnt);

    mwArray X(1,ydData.refCnt,mxDOUBLE_CLASS);
    X.SetData(refData.ARef,ydData.refCnt);

    mwArray newX;
    matlabHandler.IterativeMode(1,newX,Txy,F,yd,y,X,Nfft,Fs,Alpha);

    for(int i=0;i<ydData.refCnt;i++){
       refData.ARef[i]=newX(1,i+1);
       refData.VRef[i]=refData.SRef[i]=0;
    }
    QString mess="驱动信号已迭代更新";
    QMessageBox::warning(this,"提示",mess,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
    waveModeTmp=SineWaveFlag;
}

//refData.ARef->refData.VRef、refData.SRef
void IterativeControlMainWindow::refDataConvert(){
    mwArray accData(1,refData.refCnt,mxDOUBLE_CLASS);
    accData.SetData(refData.ARef,refData.refCnt);

    mwArray Fs(1,1,mxDOUBLE_CLASS);
    double FsArray[]={1000/refData.dataRefSampleT};
    Fs.SetData(FsArray,1);

    mwArray corr_a,corr_v,corr_s;
    matlabHandler.earthPreprocess(3,corr_a,corr_v,corr_s,accData,Fs);

    for(int i=1;i<=refData.refCnt;i++){
        refData.ARef[i-1]=corr_a(1,i);
        refData.VRef[i-1]=corr_v(1,i);
        refData.SRef[i-1]=corr_s(1,i);
    }
    QString mess="加速度信号频域积分完成";
    QMessageBox::warning(this,"提示",mess,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
}
//将得到的驱动信号积分得到速度和位移
void IterativeControlMainWindow::on_btn_integral1_clicked(){
    refDataConvert();
}

void IterativeControlMainWindow::on_btn_integral2_clicked(){
    refDataConvert();
}

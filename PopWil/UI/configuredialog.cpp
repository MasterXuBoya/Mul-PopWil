#include "configuredialog.h"
#include <QMessageBox>
#include <QtDebug>
#include <QProcess>
#include <QFileDialog>

ConfigureDialog::ConfigureDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	//Set the minimum and close button of the main frame.
	this->setWindowFlags(Qt::WindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint));

	connect(ui.cmbDevice, SIGNAL(currentIndexChanged(int)), this, SLOT(DeviceChanged(int)));
	connect(ui.btnOK, SIGNAL(clicked()), this, SLOT(ButtonOKClicked()));
	connect(ui.btnCancel, SIGNAL(clicked()), this, SLOT(ButtonCancelClicked()));	
	Initailization();
    //qDebug()<<"the window is :"<<configure.channelStart<<configure.channelCount<<configure.deviceName;
    ui.radioButton_ENC->setChecked(true);
    ui.radioButton_SSI->setChecked(false);
}

ConfigureDialog::~ConfigureDialog()
{
	
}
//将Ini文件中默认的配置显示出来
void ConfigureDialog::SetConfigureParameterAO(ConfigureParameterAO tmpConfigure,ConfigureParameterAI tmpConfigureAI)
{
    configure=tmpConfigure;
    ui.cmbDevice->setCurrentIndex(0);
    ui.cmbChannelStart->setCurrentIndex(0);
    ui.cmbChannelCount->setCurrentIndex(0);
    ui.cmbValueRange->setCurrentIndex(2);

    //---------------------------------------
    configureAI=tmpConfigureAI;
    ui.cmbChannelStart_AI->setCurrentIndex(0);
    ui.cmbChannelCount_AI->setCurrentIndex(0);
    ui.cmbValueRange_AI->setCurrentIndex(4);
    ui.edtClockRatePerChan_AI->setText(QString::number(configureAI.clockRatePerChan));
    ui.edtSectionLength_AI->setText(QString::number(configureAI.sectionLength));

}

void ConfigureDialog::Initailization()
{
    InstantAoCtrl * instantAoCtrl = InstantAoCtrl::Create();
    Array<DeviceTreeNode> *supportedDevices = instantAoCtrl->getSupportedDevices();

    if (supportedDevices->getCount() == 1)
	{
		QMessageBox::information(this, tr("Warning Information"), 
			tr("No device to support the currently demonstrated function!"));
		QCoreApplication::quit();
	} 
	else
	{
		for (int i = 0; i < supportedDevices->getCount(); i++)
		{
			DeviceTreeNode const &node = supportedDevices->getItem(i);
			qDebug("%d, %ls\n", node.DeviceNumber, node.Description);
			ui.cmbDevice->addItem(QString::fromWCharArray(node.Description));
		}
		ui.cmbDevice->setCurrentIndex(0);
	}
	configure.profilePath = L"";
	instantAoCtrl->Dispose();
	supportedDevices->Dispose();

}

void ConfigureDialog::CheckError(ErrorCode errorCode)
{
	if (errorCode >= 0xE0000000 && errorCode != Success)
	{
		QString message = tr("Sorry, there are some errors occurred, Error Code: 0x") +
			QString::number(errorCode, 16).right(8).toUpper();
		QMessageBox::information(this, "Warning Information", message);
	}
}


/*ValueRange:
 *  Array<ValueRange>* ValueRanges存储ValueRange数组，
 *  ui.cmbValueRange将这些ValueRanges类型的数据转化成可视化的实际电压
 *  ui.cmbValueRange自身还有标号i
*/
void ConfigureDialog::DeviceChanged(int index)
{
	ui.cmbChannelCount->clear();
	ui.cmbChannelStart->clear();
	ui.cmbValueRange->clear();

    std::wstring description = ui.cmbDevice->currentText().toStdWString();
    DeviceInformation selected(description.c_str());

    InstantAoCtrl * instantAoCtrl = InstantAoCtrl::Create();
	ErrorCode errorCode = instantAoCtrl->setSelectedDevice(selected);
	ui.btnOK->setEnabled(true);
	if (errorCode != 0){
		QString str;
        QString des = QString::fromStdWString(description);
		str.sprintf("Error:the error code is 0x%x\n\
                   The %s is busy or not exit in computer now.\n\
                   Select other device please!", errorCode, des.toUtf8().data());
		QMessageBox::information(this, "Warning Information", str);
		ui.btnOK->setEnabled(false);
		return;
	}

	int channelCount = (instantAoCtrl->getChannelCount() < 2) ? 
		instantAoCtrl->getChannelCount() : 2;
	int logicChannelCount = instantAoCtrl->getChannelCount();

	for (int i = 0; i < logicChannelCount; i++)
	{
		ui.cmbChannelStart->addItem(QString("%1").arg(i));
	}

	for (int i = 0; i < channelCount; i++)
	{
		ui.cmbChannelCount->addItem(QString("%1").arg(i + 1));
	}

	Array<ValueRange>* ValueRanges = instantAoCtrl->getFeatures()->getValueRanges();
	wchar_t		 vrgDescription[128];
	MathInterval ranges;
	for (int i = 0; i < ValueRanges->getCount(); i++)
	{
		if (ValueRanges->getItem(i) < UserCustomizedVrgStart) {
			errorCode = AdxGetValueRangeInformation(ValueRanges->getItem(i), sizeof(vrgDescription), vrgDescription, &ranges, NULL);
			CheckError(errorCode);
			QString str = QString::fromWCharArray(vrgDescription);
			ui.cmbValueRange->addItem(str);
		}
	}

	instantAoCtrl->Dispose();

	//Set the default value.
	ui.cmbChannelStart->setCurrentIndex(0);
	ui.cmbChannelCount->setCurrentIndex(1);
	ui.cmbValueRange->setCurrentIndex(0);


    //---------------------------------AO------------------------------------------
    ui.cmbChannelCount_AI->clear();
    ui.cmbChannelStart_AI->clear();
    ui.cmbValueRange_AI->clear();


    WaveformAiCtrl * waveformAiCtrl = WaveformAiCtrl::Create();
    errorCode = waveformAiCtrl->setSelectedDevice(selected);
    ui.btnOK->setEnabled(true);
    if (errorCode != 0){
        QString str;
        QString des = QString::fromStdWString(description);
        str.sprintf("Error:the error code is 0x%x\n\
                   The %s is busy or not exit in computer now.\n\
                   Select other device please!", errorCode, des.toUtf8().data());
        QMessageBox::information(this, "Warning Information", str);
        ui.btnOK->setEnabled(false);
        return;
    }

    channelCount = (waveformAiCtrl->getChannelCount() < 16) ?
      waveformAiCtrl->getChannelCount() : 16;
    logicChannelCount = waveformAiCtrl->getChannelCount();

    for (int i = 0; i < logicChannelCount; i++)
    {
        ui.cmbChannelStart_AI->addItem(QString("%1").arg(i));
    }

    for (int i = 0; i < channelCount; i++)
    {
        ui.cmbChannelCount_AI->addItem(QString("%1").arg(i + 1));
    }

    Array<ValueRange> *ValueRangesAI = waveformAiCtrl->getFeatures()->getValueRanges();
    wchar_t		 vrgDescriptionAI[128];
    MathInterval rangesAI;
    ValueUnit		valueUnit;
    for(int i = 0; i < ValueRangesAI->getCount(); i++)
    {
        errorCode = AdxGetValueRangeInformation(ValueRangesAI->getItem(i),
            sizeof(vrgDescriptionAI), vrgDescriptionAI, &rangesAI, &valueUnit);
        CheckError(errorCode);

        //qDebug()<<ValueRangesAI->getItem(i);

        //we filter the Celsius degree for the buffered AI can not support this function.
        if (valueUnit == CelsiusUnit)
        {
            continue;
        }

        QString str = QString::fromWCharArray(vrgDescriptionAI);
        ui.cmbValueRange_AI->addItem(str);
    }
    waveformAiCtrl->Dispose();

    //Set the default value.
    ui.cmbChannelStart->setCurrentIndex(0);
    ui.cmbChannelCount->setCurrentIndex(1);
    ui.cmbValueRange->setCurrentIndex(0);
}

void ConfigureDialog::ButtonOKClicked()
{
	if (ui.cmbDevice->count() == 0)
	{
		QCoreApplication::quit();
	}

    std::wstring description = ui.cmbDevice->currentText().toStdWString();
    DeviceInformation selected(description.c_str());

    InstantAoCtrl * instantAoCtrl = InstantAoCtrl::Create();
	ErrorCode errorCode = instantAoCtrl->setSelectedDevice(selected);
	CheckError(errorCode); 

	Array<ValueRange>* ValueRanges  = instantAoCtrl->getFeatures()->getValueRanges();
	configure.deviceName = ui.cmbDevice->currentText();
	configure.channelStart = ui.cmbChannelStart->currentText().toInt();
	configure.channelCount = ui.cmbChannelCount->currentText().toInt();
	configure.valueRange = ValueRanges->getItem(ui.cmbValueRange->currentIndex());	
	instantAoCtrl->Dispose();

    //---------------------------AI------------------------------------------------

    WaveformAiCtrl * waveformAiCtrl = WaveformAiCtrl::Create();
    errorCode = waveformAiCtrl->setSelectedDevice(selected);

    ValueRanges = waveformAiCtrl->getFeatures()->getValueRanges();

    configureAI.deviceName=ui.cmbDevice->currentText();
    configureAI.channelStart=ui.cmbChannelStart_AI->currentText().toInt();
    configureAI.channelCount=ui.cmbChannelCount_AI->currentText().toInt();
    //qDebug()<<"the current index is :"<<ui.cmbValueRange_AI->currentIndex();
    configureAI.valueRange=ValueRanges->getItem(ui.cmbValueRange_AI->currentIndex());
    //qDebug()<<configureAI.valueRange;
    configureAI.clockRatePerChan=ui.edtClockRatePerChan_AI->text().toInt();
    configureAI.sectionLength=ui.edtSectionLength_AI->text().toInt();
	this->accept();
}

void ConfigureDialog::ButtonCancelClicked()
{
    //qDebug()<<"the window is :"<<configure.channelStart<<configure.channelCount<<configure.deviceName;

	this->reject();
}

void ConfigureDialog::on_radioButton_ENC_clicked()
{
    ssiEnable=false;
}

void ConfigureDialog::on_radioButton_SSI_clicked()
{
    ssiEnable=true;
}

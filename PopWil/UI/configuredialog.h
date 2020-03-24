#ifndef CONFIGUREDIALOG_H
#define CONFIGUREDIALOG_H

#include <QDialog>
#include "ui_configuredialog.h"
#include "bdaqctrl.h"
#include "constvar.h"

using namespace Automation::BDaq;

class ConfigureDialog : public QDialog
{
	Q_OBJECT

public:
	ConfigureDialog(QWidget *parent = 0);
	~ConfigureDialog();
	void Initailization();
	void CheckError(ErrorCode errorCode);
    ConfigureParameterAO GetConfigureParameter(){return configure;}
    ConfigureParameterAI GetConfigureParameterAI(){return configureAI;}
    void SetConfigureParameterAO(ConfigureParameterAO tmpConfigure,ConfigureParameterAI tmpConfigureAI);

private:
	Ui::ConfigureDialog ui;
    ConfigureParameterAO configure;
    ConfigureParameterAI configureAI;

	private slots:
		void DeviceChanged(int index);
		void ButtonOKClicked();
		void ButtonCancelClicked();
        void on_radioButton_ENC_clicked();
        void on_radioButton_SSI_clicked();
};

#endif // CONFIGUREDIALOG_H

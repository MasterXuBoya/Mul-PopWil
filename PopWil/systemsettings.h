#ifndef SYSTEMSETTINGS_H
#define SYSTEMSETTINGS_H

#include <QDialog>
#include <constvar.h>

namespace Ui {
class SystemSettings;
}

class SystemSettings : public QDialog
{
    Q_OBJECT
    
public:
    explicit SystemSettings(QWidget *parent = 0);
    ~SystemSettings();
//    TSystemInfo getSystemInfo(){return systemInfo;}
    void setSystemInfo();
private slots:
    void on_btnSaveOnce_clicked();
    void on_btnClose_clicked();
private:
    Ui::SystemSettings *ui;
};

#endif // SYSTEMSETTINGS_H

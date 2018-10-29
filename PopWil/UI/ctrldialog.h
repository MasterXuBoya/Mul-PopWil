#ifndef CTRLDIALOG_H
#define CTRLDIALOG_H

#include <QDialog>
#include "constvar.h"
#include "qstring.h"

namespace Ui {
class CtrlDialog;
}

class CtrlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CtrlDialog(QWidget *parent = 0);
    ~CtrlDialog();
    void setPIDParameter();

private slots:
    void on_btnOk_clicked();
    void on_btnQuit_clicked();
    void DeviceChanged(int index);

private:
    Ui::CtrlDialog *ui;
    QStringList ctrlModeSet;
};

#endif // CTRLDIALOG_H

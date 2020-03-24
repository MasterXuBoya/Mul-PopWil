#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <QDialog>

namespace Ui {
class calibration;
}

class calibration : public QDialog
{
    Q_OBJECT

public:
    explicit calibration(QWidget *parent = 0);
    ~calibration();

private slots:
    void on_btn_ok_clicked();

    void on_btn_ok_2_clicked();

private:
    Ui::calibration *ui;
};

#endif // CALIBRATION_H

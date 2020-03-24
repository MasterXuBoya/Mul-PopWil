#ifndef ITERATIVECONTROLMAINWINDOW_H
#define ITERATIVECONTROLMAINWINDOW_H

#include <QMainWindow>
#include "QDebug"
#include "constvar.h"
#include "qfile.h"
#include "QString"
#include "signalprocess.h"
#include "qstandarditemmodel.h"
#include <QFileDialog>
#include "qchartviewer.h"
#include "ToolFromMatlab.h"
#include "qmessagebox.h"
//此处变成全局变量了，放在内部可能会超栈
extern TRefData earthquakeInterpolation,InterpolationOut;
extern double interpolationIndex[50000];

namespace Ui {
class IterativeControlMainWindow;
}

class IterativeControlMainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit IterativeControlMainWindow(QWidget *parent = 0);
    ~IterativeControlMainWindow();
    void tableViewShow();
    void draw();
    void refDataConvert();

private slots:
    void on_btn_open_clicked();
    void on_btn_open_2_clicked();

    void on_btn_save_clicked();

    void on_btn_resample_clicked();

    void on_btn_resample_save_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_btn_model_save_clicked();

    void on_pushButton_2_clicked();

    void on_btn_load_yd_clicked();

    void on_btn_load_model_clicked();

    void on_btn_cal_drive_clicked();

    void on_btn_fresh_clicked();

    void on_btn_integral1_clicked();

    void on_btn_integral2_clicked();

protected:
    virtual void paintEvent(QPaintEvent *event);
private:
    Ui::IterativeControlMainWindow *ui;
    TRefData earthquakeTmpData;
    SignalProcess signalHanler;
    QStandardItemModel *accModel,*velModel,*disModel;
    QChartViewer *m_acc,*m_vel,*m_dis,*m_Acc_Interpolation;
};

#endif // ITERATIVECONTROLMAINWINDOW_H

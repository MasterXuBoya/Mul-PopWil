#ifndef SINESWEEPMODULE_H
#define SINESWEEPMODULE_H

#include <QMainWindow>
struct sineSweepNode
{
    double time,value,fre;
    sineSweepNode(){}
    sineSweepNode(double time_,double value_,double fre_):time(time_),value(value_),fre(fre_){}
};

namespace Ui {
class SineSweepModule;
}

class SineSweepModule : public QMainWindow
{
    Q_OBJECT

public:
    explicit SineSweepModule(QWidget *parent = 0);
    ~SineSweepModule();
    void sweep_generator(int type,int f0,int f1,int sample,double peak,int sweepTime);

private slots:
    void on_btn_close_clicked();

    void on_btn_generate_clicked();

    void on_btn_clear_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_clicked();

private:
    Ui::SineSweepModule *ui;
};

#endif // SINESWEEPMODULE_H

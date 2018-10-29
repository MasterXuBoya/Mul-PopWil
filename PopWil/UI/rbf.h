#ifndef RBF_H
#define RBF_H

#include <QMainWindow>
#define LEN 3000

namespace Ui {
class RBF;
}

class RBF : public QMainWindow
{
    Q_OBJECT

public:
    explicit RBF(QWidget *parent = 0);
    ~RBF();
    void work();
    void drawData();
    void drawYm();
    void drawJacobian();

private:
    Ui::RBF *ui;
    double time[LEN],u[LEN],y[LEN],ym[LEN]={0},em[LEN],dyu[LEN]={0};
};

#endif // RBF_H

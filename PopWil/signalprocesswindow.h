#ifndef SIGNALPROCESSWINDOW_H
#define SIGNALPROCESSWINDOW_H

#include <QMainWindow>

namespace Ui {
class SignalProcessWindow;
}

class SignalProcessWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignalProcessWindow(QWidget *parent = 0);
    ~SignalProcessWindow();

private:
    Ui::SignalProcessWindow *ui;
};

#endif // SIGNALPROCESSWINDOW_H

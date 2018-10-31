#ifndef DISPLAYBUFFERFORM_H
#define DISPLAYBUFFERFORM_H

#include <QDialog>

namespace Ui {
class DisplayBufferForm;
}

class DisplayBufferForm : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayBufferForm(QWidget *parent = 0);
    ~DisplayBufferForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DisplayBufferForm *ui;
};

#endif // DISPLAYBUFFERFORM_H

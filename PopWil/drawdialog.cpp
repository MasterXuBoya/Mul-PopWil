#include "drawdialog.h"
#include "ui_drawdialog.h"

DrawDialog::DrawDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawDialog)
{
    ui->setupUi(this);
}

DrawDialog::~DrawDialog()
{
    delete ui;
}

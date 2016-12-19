#include "dialog.h"
#include "ui_dialog.h"
#include "playwindow.h"
#include "form.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    PlayWindow *P = new PlayWindow();
    P->setMode(1);
    P->setBegin();
    P->show();
    this->close();
}

void Dialog::on_pushButton_2_clicked()
{
    PlayWindow *P = new PlayWindow();
    P->setMode(2);
    P->setBegin();
    P->show();
    this->close();
}

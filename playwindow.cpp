#include "playwindow.h"
#include "ui_playwindow.h"
#include "QKeyEvent"
#include "form.h"

PlayWindow::PlayWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
}

PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
        this->close();
}

void PlayWindow::on_pushButton_clicked()
{
    this->ui->pushButton->setDisabled(true);
    this->ui->pushButton_2->setDisabled(true);
    Form *F = new Form(this);
    F->setColors(1,2);
    F->setPlayerName(this->playerName);
    F->show();
}

void PlayWindow::on_pushButton_2_clicked()
{
    this->ui->pushButton->setDisabled(true);
    this->ui->pushButton_2->setDisabled(true);
    Form *F = new Form(this);
    F->setColors(2,1);
    F->setPlayerName(this->playerName);
    F->setBeginPosition();
    F->show();
}

int PlayWindow::getHColor()
{
    return this->hColor;
}

void PlayWindow::setMode(int value)
{
    this->mode = value;
    if (value == 2)
    {
        this->ui->pushButton->setDisabled(true);
        this->ui->pushButton_2->setDisabled(true);
        this->ui->pushButton_3->setDisabled(true);
        Form *F = new Form(this);
        F->setColors(0,0);
        F->show();
    }
}

void PlayWindow::setPlayerName(char *name)
{
    strcpy(this->playerName, name);
}

void PlayWindow::on_pushButton_3_clicked()
{
    if (ui->lineEdit->text().isEmpty())
        this->setPlayerName("");
    else
    {
        char n[40];
        strcpy(n, ui->lineEdit->text().toStdString().c_str());
        this->setPlayerName(n);
    }
    if (strcmp(this->playerName, ""))
        ui->pushButton->setEnabled(true), ui->pushButton_2->setEnabled(true);
}

void PlayWindow::setBegin()
{
    if (this->mode == 1)
        ui->pushButton->setDisabled(true), ui->pushButton_2->setDisabled(true);
    if (this->mode == 2)
        ui->pushButton->setDisabled(true), ui->pushButton_2->setDisabled(true), ui->pushButton_3->setDisabled(true);
}

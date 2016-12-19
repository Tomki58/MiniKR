#include "form.h"
#include "ui_form.h"
#include "QPainter"
#include "QList"
#include "QShortcut"
#include "QKeyEvent"
#include "ctime"
#include "playwindow.h"
#include "dos.h"
#include "cstdio"

Field *F = new Field;


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setMouseTracking(true);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Background, QColor(Qt::white));
    this->setPalette(palette);
    this->setAutoFillBackground(true);
    this->setPlayerName("");
}


int i = 2;

Form::~Form()
{
    delete ui;
}
QPalette palette;
QPainter L;
QList<QPoint> mass;
QPoint current;

void Form::paintEvent(QPaintEvent *event)
{
    L.begin(this);
    for (int i = 195; i <= 1366; i+=195)
    {
        L.setPen(Qt::black);
        L.drawLine(i, 0, i, height());
    }
    for (int i = 100; i <= 600; i+=100)
    {
        L.setPen(Qt::black);
        L.drawLine(0, i, width(), i);
    }
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 7; j++)
            switch (F->getColor(i,j).getColor())
            {
            case 1:
            {
                L.setPen(Qt::red);
                L.setBrush(Qt::red);
                L.drawEllipse(i*195 + 70, j*100 + 12, 64, 64);
                break;
            }
            case 2:
            {
                L.setPen(Qt::blue);
                L.setBrush(Qt::blue);
                L.drawEllipse(i*195 + 70, j*100 + 12, 64, 64);
                break;
            }
            default:
                break;
            }

    L.end();
}

void Form::mousePressEvent(QMouseEvent *event)
{
    if (!strcmp(this->playerName, "") && this->PlayerColor != 0 && this->compColor != 0)
        this->setDisabled(true);
    else
        if (strcmp(this->playerName, ""))
            this->setEnabled(true);
    if (F->isFull() == 0)
    {
        FILE *f;
        char Name[20];
        strcpy(Name, __DATE__);
        strcat(Name, ".txt");
        f = fopen(Name, "a");
        char result[40]; char name[40];
        strcpy(name, this->playerName);
        time_t seconds = time(NULL);
        tm* timeinfo = localtime(&seconds);
        strcpy(result, strcat(strcat(asctime(timeinfo), strcat(name, " draw")), "\n"));
        fputs(result, f);
        fclose(f);
        this->setDisabled(true);
    }
    else
    {
        if (this->compColor != 0 && this->PlayerColor != 0)
        {
            if (F->isRowAvailable((QCursor::pos().x() - parentWidget()->pos().x())/195) == true)
            {
                Chip *C = new Chip((QCursor::pos().x() - parentWidget()->pos().x())/195, PlayerColor);
                F->addChip(*C);
                if (F->getMaxLengthH(PlayerColor) == 4)
                {
                    char win[40]; char lose[40];
                    int wins, loses;
                    FILE *f;
                    char Name[20];
                    strcpy(Name, __DATE__);
                    strcat(Name, ".txt");
                    f = fopen(Name, "a");
                    char result[40]; char name[40];
                    strcpy(name, this->playerName);
                    time_t seconds = time(NULL);
                    tm* timeinfo = localtime(&seconds);
                    strcpy(result, strcat(strcat(asctime(timeinfo), strcat(name, " win")), "\n"));
                    fputs(result, f);
                    fclose(f);
                    char filename[40];
                    strcpy(filename,strcat(this->playerName,".txt"));
                    if ((f = fopen(filename, "r")) != NULL)
                    {
                        fgets(win, 40, f);
                        fgets(win, 40, f);
                        fgets(lose, 40, f);
                        fgets(lose, 40, f);
                        wins = atoi(win);
                        wins++;
                        fclose(f);
                        itoa(wins, win, 10);
                        f = fopen(this->playerName, "w");
                        fputs("Wins:\n", f);
                        fputs(strcat(win, "\n"),f);
                        fputs("Loses:\n",f);
                        fputs(lose,f);
                        fclose(f);
                    }
                    else
                    {
                        f = fopen(this->playerName, "w");
                        fputs("Wins:\n", f);
                        fputs("1\n",f);
                        fputs("Loses:\n",f);
                        fputs("0\n",f);
                        fclose(f);
                    }

                    this->setDisabled(true);
                }
                else
                    F->compTurn(compColor);
                if (F->getMaxLengthH(compColor) == 4)
                {
                    char win[40]; char lose[40];
                    int wins, loses;
                    FILE *f;
                    char Name[20];
                    strcpy(Name, __DATE__);
                    strcat(Name, ".txt");
                    f = fopen(Name, "a");
                    char result[40];
                    time_t seconds = time(NULL);
                    tm* timeinfo = localtime(&seconds);
                    strcpy(result, strcat(strcat(asctime(timeinfo), "Computer win"), "\n"));
                    fputs(result, f);
                    fclose(f);
                    this->setDisabled(true);
                    char filename[40];
                    strcpy(filename,strcat(this->playerName,".txt"));
                    if ((f = fopen(filename, "r")) != NULL)
                    {
                        fgets(win, 40, f);
                        fgets(win, 40, f);
                        fgets(lose, 40, f);
                        fgets(lose, 40, f);
                        loses = atoi(lose);
                        loses++;
                        fclose(f);
                        itoa(loses, lose, 10);
                        f = fopen(this->playerName, "w");
                        fputs("Wins:\n", f);
                        fputs(win,f);
                        fputs("Loses:\n",f);
                        fputs(lose,f);
                        fclose(f);
                    }
                    else
                    {
                        f = fopen(this->playerName, "w");
                        fputs("Wins:\n", f);
                        fputs("0\n",f);
                        fputs("Loses:\n",f);
                        fputs("1\n",f);
                        fclose(f);
                    }
                }
                update();
            }
        }
        if (PlayerColor == 0 && compColor == 0)
        {
            if (F->isRowAvailable((QCursor::pos().x() - parentWidget()->pos().x())/195) == true )
            {
                if (i == 2)
                    i = 1;
                else
                    i = 2;
            }
            Chip *C = new Chip((QCursor::pos().x() - parentWidget()->pos().x())/195, i);
            F->addChip(*C);
            if (F->getMaxLengthH(i) == 4)
            {
                FILE *f;
                char Name[20];
                strcpy(Name, __DATE__);
                strcat(Name, ".txt");
                f = fopen(Name, "a");
                char result[40]; char name[40];
                time_t seconds = time(NULL);
                tm* timeinfo = localtime(&seconds);
                if (i == 1)
                    strcpy(result, strcat(strcat(asctime(timeinfo), "Player 1 win"), "\n"));
                else
                    strcpy(result, strcat(strcat(asctime(timeinfo), "Player 2 win"), "\n"));
                fputs(result, f);
                fclose(f);
                this->setDisabled(true);
            }
        }
        update();
    }
}

void Form::setColors(int color1, int color2)
{
    this->PlayerColor = color1;
    this->compColor = color2;
}

void Form::setBeginPosition()
{
    if (strcmp(this->playerName, ""))
    {
        if (this->compColor == 1)
            F->firsTurn(compColor);
    }
}

void Form::setPlayerName(char *name)
{
    strcpy(this->playerName, name);
}


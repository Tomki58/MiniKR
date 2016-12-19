#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "field.h"
#include "playwindow.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT
    
public:
    explicit Form(QWidget *parent = 0);
    void onESCpressed();
    ~Form();
    void setColors(int, int); // установка цветов первого и второго игроков
    void setBeginPosition(); // установка начальных позиций
    void setPlayerName(char*); // установка имени игрока
    
private:
    Ui::Form *ui;
    QCursor curs;
    int compColor; // цвет компьютера
    int PlayerColor; // цвет игрока
    char playerName[40]; // имя игрока

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
};

#endif // FORM_H

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
    void setColors(int, int); // ��������� ������ ������� � ������� �������
    void setBeginPosition(); // ��������� ��������� �������
    void setPlayerName(char*); // ��������� ����� ������
    
private:
    Ui::Form *ui;
    QCursor curs;
    int compColor; // ���� ����������
    int PlayerColor; // ���� ������
    char playerName[40]; // ��� ������

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
};

#endif // FORM_H

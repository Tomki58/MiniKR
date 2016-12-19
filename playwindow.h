#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QWidget>

namespace Ui {
class PlayWindow;
}

class PlayWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit PlayWindow(QWidget *parent = 0);
    ~PlayWindow();
    int getHColor();
    void setMode(int);
    void setPlayerName(char*);
    void setBegin();
    int hColor;
    int mode;
    char playerName[40];
    
private:
    Ui::PlayWindow *ui;

protected:
    void keyPressEvent(QKeyEvent *);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // PLAYWINDOW_H

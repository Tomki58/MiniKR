#ifndef FIELD_H
#define FIELD_H
#include <chip.h>

class Field
{
private:
    Chip A[7][6];
public:
    Field();
    Chip getColor(int, int);  // получить объект класса Chip находящийся в заданных координатах
    void addChip(const Chip); // добавить объект в матрицу
    int getMaxLengthH(int); // максимальная длина ряда заданного цвета
    void compTurn(int); // ход компьютера
    void firsTurn(int); // первый ход компьютера
    bool isRowAvailable(int); // есть ли свободные клетки по вертикали в данном ряду
    bool isFull(); // проверка на доступные ходы
    bool isAvailable(int, int); // доступна ли данная клетка
    int isEmpty(); // пуста ли матрица
    int firstEmptyVer(int); // у координата первой свободной клетки в ряду
    ~Field(); // деструктор
    bool getColorUp(int, int); // получение цвета клетки стоящей выше
    bool getColorDiRightUp(int, int); // получение цвета клетки стоящей диагонально верх справа
    bool getColorLeft(int, int); // получение цвета клетки стоящей слева
    bool getColorDiLeftUp(int, int); // получение цвета клетки стоящей диагонально влево вверх
    bool getColorRight(int, int); // получение цвета клетки стоящей справа
    int getMark(int, int); // получение оценки хода
};

#endif // FIELD_H

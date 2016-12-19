#ifndef CHIP_H
#define CHIP_H

class Chip
{
private:
    int x; // координата матрицы в которую помещается данная фишка
    int color; //1 - красный, 2 - синий
public:
    Chip(); // конструктор по умолчанию
    int getX(); // метод для получения координаты фишки
    Chip(int, int); // конструктор инициализации
    int getColor(); // метод для получения цвета фишки
    ~Chip(); // деструктор
};

#endif // CHIP_H

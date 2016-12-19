#ifndef CHIP_H
#define CHIP_H

class Chip
{
private:
    int x; // ���������� ������� � ������� ���������� ������ �����
    int color; //1 - �������, 2 - �����
public:
    Chip(); // ����������� �� ���������
    int getX(); // ����� ��� ��������� ���������� �����
    Chip(int, int); // ����������� �������������
    int getColor(); // ����� ��� ��������� ����� �����
    ~Chip(); // ����������
};

#endif // CHIP_H

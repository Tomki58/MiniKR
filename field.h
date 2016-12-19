#ifndef FIELD_H
#define FIELD_H
#include <chip.h>

class Field
{
private:
    Chip A[7][6];
public:
    Field();
    Chip getColor(int, int);  // �������� ������ ������ Chip ����������� � �������� �����������
    void addChip(const Chip); // �������� ������ � �������
    int getMaxLengthH(int); // ������������ ����� ���� ��������� �����
    void compTurn(int); // ��� ����������
    void firsTurn(int); // ������ ��� ����������
    bool isRowAvailable(int); // ���� �� ��������� ������ �� ��������� � ������ ����
    bool isFull(); // �������� �� ��������� ����
    bool isAvailable(int, int); // �������� �� ������ ������
    int isEmpty(); // ����� �� �������
    int firstEmptyVer(int); // � ���������� ������ ��������� ������ � ����
    ~Field(); // ����������
    bool getColorUp(int, int); // ��������� ����� ������ ������� ����
    bool getColorDiRightUp(int, int); // ��������� ����� ������ ������� ����������� ���� ������
    bool getColorLeft(int, int); // ��������� ����� ������ ������� �����
    bool getColorDiLeftUp(int, int); // ��������� ����� ������ ������� ����������� ����� �����
    bool getColorRight(int, int); // ��������� ����� ������ ������� ������
    int getMark(int, int); // ��������� ������ ����
};

#endif // FIELD_H

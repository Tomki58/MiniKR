#include "field.h"

Chip Field::getColor(int x, int y)
{
    Chip *obj = new Chip;
    *obj = this->A[x][y];
    return *obj;
}

void Field::addChip(Chip obj)
{
    int y = 5;
    while (this->A[obj.getX()][y].getColor() != 0)
        y--;
    if (y >= 0)
    {
        this->A[obj.getX()][y] = obj;
    }
}

Field::Field()
{
    for (int i = 0; i < 7; i++)
    {
        Chip *C = new Chip(i, 0);
        **A = *C;
        for (int j = 0; j < 6; j++)
            this->addChip(*C);
    }
}

bool Field::isFull()
{
    int count = 0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 6; j++)
        {
            if (this->getColor(i,j).getColor() == 0)
                count++;
        }
    return count;
}

bool Field::getColorUp(int x, int y)
{
    if (y != 0)
    {
        if (A[x][y].getColor() == A[x][y-1].getColor())
            return 1;
        else
            return 0;
    }
    else
            return 0;
}

bool Field::getColorLeft(int x, int y)
{
    if (x != 0)
        return (A[x][y].getColor() == A[x-1][y].getColor()) ? 1 : 0;
    else
        return 0;
}

bool Field::getColorDiLeftUp(int x, int y)
{
    if (x != 0 && y!= 0)
        return (A[x][y].getColor() == A[x-1][y-1].getColor()) ? 1 : 0;
    else
        return 0;
}

bool Field::getColorDiRightUp(int x, int y)
{
    if (x != 6 && y != 0)
        return (A[x][y].getColor() == A[x+1][y-1].getColor()) ? 1 : 0;
    else
        return 0;
}

bool Field::getColorRight(int x, int y)
{
    if (x != 6)
        return (A[x][y].getColor() == A[x+1][y].getColor()) ? 1 : 0;
    else
        return 0;
}

int Field::getMaxLengthH(int color)
{
    int length = 1; int i; int j;
    int maxlength = 0;
    for (i = 0; i < 7; i++)
        for (j = 0; j < 6; j++)
        {
            if (A[i][j].getColor() == color)
            {
                length = 1;
                int x = i; int y = j;
                while (this->getColorUp(x,y) && length != 4)
                    y--, length++;
                if (length <= 4)
                {
                    if (length > maxlength)
                    {
                        maxlength = length;
                    }
                    length = 1; x = i; y = j;
                }
                while (this->getColorLeft(x,y) && length != 4)
                    x--, length++;
                if (length <= 4)
                {
                    if (length > maxlength)
                    {
                        maxlength = length;
                    }
                    length = 1; x = i; y = j;
                }
                while (this->getColorDiLeftUp(x,y) && length != 4)
                    x--, y--, length++;
                if (length <= 4)
                {
                    if (length > maxlength)
                    {
                        maxlength = length;
                    }
                    length = 1; x = i; y = j;
                }
                while (this->getColorDiRightUp(x,y) && length != 4)
                    x++, y--, length++;
                if (length <= 4)
                {
                    if (length > maxlength)
                    {
                        maxlength = length;
                    }
                    length = 1; x = i; y = j;
                }
            }
        }
    return maxlength;
}

void Field::compTurn(int color)
{
    bool flag1 = false;
    int opColor;
    if (color == 1)
        opColor = 2;
    else
        opColor = 1;
    if (this->isFull() != 0)
    {
        int lenght;
        if (this->getMaxLengthH(color) == 3)
        {
            bool flag = false;
            for (int i = 0; i < 7; i++)
                for (int j = 0; j < 6; j++)
                {
                    if (A[i][j].getColor() == color)
                    {
                        lenght = 1;
                        int x = i; int y = j;
                        while (this->getColorUp(x,y) && lenght != 3)
                            y--, lenght++;
                        if (lenght == 3 && this->isAvailable(i,y-1) && flag1 == false)
                        {
                            Chip *C = new Chip(i,color);
                            this->addChip(*C);
                            flag = true;
                            flag1 = true;
                        }
                        else
                        {
                            lenght = 1;
                            x = i; y = j;
                        }
                        while (this->getColorLeft(x,y) && lenght != 3 && flag == false)
                            x--, lenght++;
                        if (lenght == 3 && this->firstEmptyVer(x-1) == y && flag1 == false)
                        {
                            Chip *C = new Chip(x-1, color);
                            this->addChip(*C);
                            flag = true;
                            flag1 = true;
                        }
                    }
                }
        }
        if (this->getMaxLengthH(opColor) == 3 && flag1 == false)
        {
            bool flag = false;
            for (int i = 0; i < 7; i++)
                for (int j = 0; j < 6; j++)
                {
                    if (A[i][j].getColor() == opColor)
                    {
                        lenght = 1;
                        int x = i; int y = j;
                        while (this->getColorUp(x,y) && lenght != 3)
                            y--, lenght++;
                        if (lenght == 3 && this->isAvailable(i,y-1) && flag1 == false)
                        {
                            Chip *C = new Chip(i,color);
                            this->addChip(*C);
                            flag = true;
                            flag1 = true;
                        }
                        else
                        {
                            lenght = 1;
                            x = i; y = j;
                        }
                        while (this->getColorLeft(x,y) && lenght != 3 && flag == false)
                            x--, lenght++;
                        if (lenght == 3 && this->firstEmptyVer(x-1) == y && this->isAvailable(x-1,j) && flag1 == false)
                        {
                            Chip *C = new Chip(x-1, color);
                            this->addChip(*C);
                            flag = true;
                            flag1 = true;
                        }
                        else
                        {
                            lenght = 1;
                            x = i; y = j;
                        }
                        while (this->getColorRight(x,y) && lenght != 3 && flag == false)
                            x++, lenght++;
                        if (lenght == 3 && this->firstEmptyVer(x+1) == y && this->isAvailable(x+1, j) && flag1 == false)
                        {
                            Chip *C = new Chip(x+1,color);
                            this->addChip(*C);
                            flag = true;
                            flag1 = true;
                        }
                    }
                }

        }
        else
            if (this->getMaxLengthH(opColor) != 3 && flag1 == false)
            {
                int x;
                int maxMark = -128;
                for (int i = 0; i < 7; i++)
                {
                    if (this->getMark(i, color) >= maxMark)
                    {
                        if (this->isAvailable(i,this->firstEmptyVer(i)) && flag1 == false)
                        {
                            maxMark = this->getMark(i,color);
                            x = i;
                        }
                    }
                }
                Chip *C = new Chip(x,color);
                this->addChip(*C);
                flag1 = true;
            }
        if (flag1 == false)
        {
            int x;
            int maxMark = -128;
            for (int i = 0; i < 7; i++)
            {
                if (this->getMark(i, color) >= maxMark)
                {
                    if (this->isAvailable(i,this->firstEmptyVer(i)) && flag1 == false)
                    {
                        maxMark = this->getMark(i,color);
                        x = i;
                    }
                }
            }
            Chip *C = new Chip(x,color);
            this->addChip(*C);
            flag1 = true;
        }
    }
}

bool Field::isAvailable(int x, int y)
{
    if (this->A[x][y].getColor() == 0 && x >= 0 && x <= 6 && y >= 0 && y <= 5 )
        return 1;
    else
        return 0;
}

int Field::firstEmptyVer(int x)
{
    int i;
    for (i = 5; i >= 0 && A[x][i].getColor() != 0; i--);
    return i;
}

int Field::isEmpty()
{
    int count = 1;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 6; j++)
            if (this->A[i][j].getColor() != 0)
                count++;
    return count;
}

int Field::getMark(int x, int color)
{
    int opColor;
    if (color == 1)
        opColor = 2;
    else
        opColor = 1;

    int y = firstEmptyVer(x); int i;
    int mark = 0;
    if (y == -1)
        return 0;
    if (y == 4 || y == 3 || y == 2 || y == 1)
    {
        if (A[x][y+1].getColor() == color)
            mark += 2;
        if (A[x][y+1].getColor() == opColor)
            mark -= 10;
        if (A[x][y-1].getColor() == color)
            mark += 2;
        if (A[x][y-1].getColor() == opColor)
            mark -= 10;
        mark += y - 0;
    }
    if (y == 5)
        mark += (y - 0)*2;
    if (y == 0)
    {
        if (A[x][y+1].getColor() == color)
            mark += 2;
        if (A[x][y+1].getColor() == opColor)
            mark -= 10;
    }
    if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5)
    {
        if (y == 5)
        {
            if (A[x-1][y].getColor() == color)
                mark += 2;
            if (A[x-1][y].getColor() == opColor)
                mark -= 10;
            if (A[x-1][y].getColor() == 0)
            {
                mark += 2;
                i = x-1;
                while (this->getColorLeft(i, y))
                    i--, mark += 2;
            }
            if (A[x+1][y].getColor() == color)
                mark += 2;
            if (A[x+1][y].getColor() == opColor)
                mark -= 10;
            if (A[x+1][y].getColor() == 0)
            {
                mark += 2;
                i = x + 1;
                while(this->getColorRight(i,y))
                    i++, mark += 2;
            }
        }
        else
        {
            if (this->firstEmptyVer(x-1) == y)
            {
                if (A[x][y].getColor() == A[x-1][y+1].getColor())
                    mark += 2;
                else
                    mark -= 10;
                if (A[x-1][y].getColor() == 0)
                {
                    mark += 2;
                    i = x - 1;
                    while (this->getColorLeft(i,y) && this->firstEmptyVer(i-1) == y)
                        i--, mark += 2;
                }
            }
            if (this->firstEmptyVer(x-1) < y)
            {
                if (A[x-1][y+1].getColor() == color)
                    mark += 2;
                else
                    mark -= 10;
                if (A[x-1][y].getColor() == color)
                    mark += 2;
                else
                    mark -= 10;
                if (y > 0)
                {
                    if (A[x-1][y-1].getColor() == color || A[x-1][y-1].getColor() == 0)
                        mark += 2;
                    else
                        mark -= 10;
                }
            }
            if (this->firstEmptyVer(x+1) == y)
            {
                if (A[x+1][y+1].getColor() == color)
                    mark += 2;
                else
                    mark -= 10;
                if (A[x+1][y].getColor() == 0)
                {
                    mark += 2;
                    i = x + 1;
                    while (this->getColorRight(i,y) && this->firstEmptyVer(i+1) == y)
                        i++, mark += 2;
                }
            }
            if (this->firstEmptyVer(x+1) < y)
            {
                if (A[x+1][y+1].getColor() == color)
                    mark += 2;
                else
                    mark -= 10;
                if (A[x+1][y].getColor() == color)
                    mark += 2;
                else
                    mark -= 10;
                if (y > 0)
                {
                    if (A[x+1][y-1].getColor() == color || A[x+1][y-1].getColor() == 0)
                        mark += 2;
                    else
                        mark -= 10;
                }
            }
        }
    }
    if (x == 0)
    {
        if (this->firstEmptyVer(x+1) == y)
        {
            if (A[x+1][y+1].getColor() == color)
                mark += 2;
            else
                mark -= 10;
            if (A[x+1][y].getColor() == 0)
            {
                mark += 2;
                i = x + 1;
                while (this->getColorRight(i,y) && this->firstEmptyVer(i+1) == y)
                    i++, mark += 2;
            }
        }
        if (this->firstEmptyVer(x+1) < y)
        {
            if (A[x+1][y+1].getColor() == color)
                mark += 2;
            else
                mark -= 10;
            if (A[x+1][y].getColor() == color)
                mark += 2;
            else
                mark -= 10;
            if (y > 0)
            {
                if (A[x+1][y-1].getColor() == color || A[x+1][y-1].getColor() == 0)
                    mark += 2;
                else
                    mark -= 10;
            }
        }
    }
    if (x == 6)
    {
        if (this->firstEmptyVer(x-1) == y)
        {
            if (A[x][y].getColor() == A[x-1][y+1].getColor())
                mark += 2;
            else
                mark -= 10;
            if (A[x-1][y].getColor() == 0)
            {
                mark += 2;
                i = x - 1;
                while (this->getColorLeft(i,y) && this->firstEmptyVer(i-1) == y)
                    i--, mark += 2;
            }
        }
        if (this->firstEmptyVer(x-1) < y)
        {
            if (A[x-1][y+1].getColor() == color)
                mark += 2;
            else
                mark -= 10;
            if (A[x-1][y].getColor() == color)
                mark += 2;
            else
                mark -= 10;
            if (y > 0)
            {
                if (A[x-1][y-1].getColor() == color || A[x-1][y-1].getColor() == 0)
                    mark += 2;
                else
                    mark -= 10;
            }
        }
    }
    return mark;
}

void Field::firsTurn(int color)
{
    Chip *C = new Chip(3, color);
    this->addChip(*C);
}

bool Field::isRowAvailable(int x)
{
    int i;
    for (i = 0; i < 6; i++)
        if (A[x][i].getColor() == 0)
            return true;
    if (i == 6)
        return false;
}

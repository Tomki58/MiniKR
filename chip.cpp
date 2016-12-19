#include "chip.h"

Chip::Chip()
{

}

Chip::Chip(int x, int color)
{
    this->x = x;
    this->color = color;
}

int Chip::getColor()
{
    return this->color;
}

Chip::~Chip()
{
}

int Chip::getX()
{
    return this->x;
}

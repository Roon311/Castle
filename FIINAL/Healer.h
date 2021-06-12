#pragma once
#include "Enemies/Enemy.h"
class Healer :
    public Enemy
{
private:
    bool Backward=false;
public:
    Healer(int id, int at, int d);
    void Move();
};
#pragma once
#include "Enemies/Enemy.h"
class Healer :
    public Enemy
{
private:
    bool Backward;
public:
    Healer(int id, int at, int d);
    void Move();
};
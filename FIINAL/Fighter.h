#pragma once
#include "Enemies/Enemy.h"
class Fighter :
    public Enemy
{
public:
    Fighter(int id, int at, int d);
    void Move();
};


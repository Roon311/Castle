#pragma once
#include "Enemies/Enemy.h"
class Healer :
    public Enemy
{
private:
    bool Backward;
public:
    void Move();
};
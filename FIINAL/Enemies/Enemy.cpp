#include "Enemy.h"


Enemy::Enemy(int id, int arrTime, int d) :ID(id), ArrvTime(arrTime)
{
	SetDistance(d);
}

Enemy::~Enemy()
{
}

int Enemy::GetID() const
{
	return ID;
}


void Enemy::SetStatus(ENMY_STATUS s)
{
	status = s;
}


ENMY_STATUS Enemy::GetStatus() const
{
	return status;
}


void Enemy::DecrementDist()
{
	if (Distance > MinDistance)
		Distance--;
}

void Enemy::SetDistance(int d)
{
	if (d >= MinDistance && d <= MaxDistance)
		Distance = d;
	else
		Distance = MaxDistance;
}

int Enemy::GetDistance() const
{
	return Distance;
}



int Enemy::GetArrvTime() const
{
	return ArrvTime;
}


void Enemy::Set_Health(int H)
{
	if (H > 0)
	{
		Health = H;
	}
	else
	{
		Health = 0;
	}
}
int Enemy::Get_Health() const
{
	return Health;
}
void Enemy::Set_Power(int POW)
{
	if (POW > 0)
	{
		Power = POW;
	}
	else
	{
		Power = 0;
	}
}
int Enemy::Get_Power() const
{
	return Power;
}
void Enemy::Set_Reload(int RLD)
{
	if (RLD > 0)
	{
		Reload_Period = RLD;
	}
	else
	{
		Reload_Period = 0;
	}
}
int Enemy::Get_Reload() const
{
	return Reload_Period;
}
void Enemy::Set_Speed(int SPD)
{
	if (SPD > 0)
	{
		Speed = SPD;
	}
	else
	{
		Speed = 0;
	}
}
int Enemy::Get_Speed() const
{
	return Speed;
}
void Enemy::Set_Type(ENMY_TYPE Type)
{
	TYPE = Type;
}
ENMY_TYPE Enemy::Get_Type() const
{
	return TYPE;
}
void Enemy::Set_Original_Health(double OH)
{
	if (OH > 0)
	{
		originalHealth = OH;
	}
	else
	{
		originalHealth = 0;
	}
}
double Enemy::Get_Original_Health() const
{
	return originalHealth;
}
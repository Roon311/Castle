#include "Castle.h"




void Castle::SetHealth(double h)
{
	if (h > 0)
		Health = h;
	else
		Health = 0; // killed
}

double Castle::GetHealth() const
{
	return Health;
}

void Castle::SetPower(double P)
{
	if (P > 0)
		Power = P;
	else
		Power = 0; // killed
}

double Castle::GetPower() const
{
	return Power;
}

void Castle::SetMax_Enemy(int M)
{
	if (M > 0)
		Max_numofenemy = M;
	else
		Max_numofenemy = 0; // killed
}
int Castle::GetMax_Enemy() const
{
	return Max_numofenemy;
}

bool Castle::Get_Frosted() const
{
	return Frosted;
}
void Castle::Set_Frosted(bool frozen)
{
	Frosted = frozen;
}


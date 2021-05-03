#pragma once
#include "..\Defs.h"
class Castle
{
	double Health;
	double Power;//Omar adding
	int Max_enemyA_Time;
	//
	// TODO: Add More Data Members As Needed
	//

public:

	void SetHealth(double h);
	double GetHealth() const;
	void SetPower(double P);//Omar adding
	double GetPower() const;//Omar adding
	void SetMax_Enemy(int M);//Omar adding
	int GetMax_Enemy() const;//Omar adding

	//
	// TODO: Add More Member Functions As Needed
	//

};



#pragma once
#include "..\Defs.h"
class Castle
{
	double Health=0;
	double Power;//Omar adding
	bool Frosted=false; //By Rodina
	int Max_numofenemy;
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
	bool Get_Frosted() const;//By Rodina
	void Set_Frosted(bool frozen);//By Rodina

	//
	// TODO: Add More Member Functions As Needed
	//

};


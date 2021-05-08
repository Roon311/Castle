#include "Fighter.h"
Fighter::Fighter(int id, int at, int d) : Enemy(id, at, d)
{
	;
}
void Fighter::Move() {
	if (Health > 0.5 * originalHealth) {
		if (Distance > 2 + Speed) {
			Distance = Distance - Speed;
		}
	}
	else {
		if (Distance > 2 + Speed * 0.5) {
			Distance = Distance - Speed * 0.5;
		}
	}
}
#include "Freezer.h"
Freezer::Freezer(int id, int at, int d) : Enemy(id, at, d)
{
	;
}
void Freezer::Move() {
	if (Health > 0.5 * originalHealth) {
		if (Distance > 2 + Speed)
			Distance -= Speed;
		else if (Distance <= 2 + Speed)
			Distance = 2;
	}
	else {
		if (Distance > 2 + Speed * 0.5)
			Distance -= Speed * 0.5;
		else if (Distance <= 2 + Speed * 0.5)
			Distance = 2;

	}
}
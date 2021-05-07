#include "Fighter.h"
void Fighter::Move() {
	if (Health > 0.5 * originalHealth) {
		if (Distance > 2 + Speed) {
			Distance = Distance - Speed;
		}
	}
	else {
		if (Distance > 2 + Speed*0.5) {
			Distance = Distance - Speed*0.5;
		}
	}
}
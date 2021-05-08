#include "Fighter.h"
void Fighter::Move() {
	if (Distance > 2 + Speed) {
		Distance = Distance - Speed;
	}
}
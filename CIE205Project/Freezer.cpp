#include "Freezer.h"
void Freezer::Move() {
	if (Distance > 2+Speed) {
		Distance = Distance - Speed;
	}
}
#include "Healer.h"
void Healer::Move() {
	if (Distance > 2 + Speed) {
		Distance = Distance - Speed;
	}
}
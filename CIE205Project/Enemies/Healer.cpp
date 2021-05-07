#include "Healer.h"
void Healer::Move() {
	if (Health > 0.5 * originalHealth) {
		if (Distance > 2 + Speed) {
			Distance = Distance - Speed;
		}
		if (Distance < 2 + Speed/2)
			Backward = true;
		return;
		if (Backward ==true) {
			Distance = Distance + Speed;
		}
		if (Distance > 60 - Speed)
			Backward = false;
		return;
	}
	else {
		if (Distance > 2 + Speed/2) {
			Distance = Distance - Speed/2;
		}
		if (Distance < 2 + Speed/2)
			Backward = true;
		return;
		if (Backward == true) {
			Distance = Distance + Speed/2;
		}
		if (Distance > 60 - Speed/2)
			Backward = false;
		return;
	}

}
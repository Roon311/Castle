#include "Healer.h"
Healer::Healer(int id, int at, int d) : Enemy(id, at, d)
{
	
}
void Healer::Move() {
	if (Health >= 0.5 * originalHealth) {
		if (Backward == false) {
			if (Distance > 2) {
				Distance = Distance - Speed;
			}
			if (Distance <= 2) {
				Distance = 2;
				Backward = true;
			}
			
		}
		else {

			if (Backward == true) {
				Distance = Distance + Speed;
			}
			if (Distance >= 60) {
				Distance = 60;
				Backward = false;
			}
		}

	}
	else {
		if (Backward == false) {
			if (Distance > 2) {
				Distance = Distance - Speed * 0.5;
			}
			if (Distance <= 2) {
				Distance = 2;
				Backward = true;
			}
			
		}
		else {

			if (Backward == true) {
				Distance = Distance + Speed * 0.5;
			}
			if (Distance > 60) {
				Distance = 60;
				Backward = false;
			}
		}
	}
}
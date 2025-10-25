#include "Triangulo.h"

Triangulo::Triangulo(int x, int y)
	: Figura(x, y, "Triangulo"), lado(10), dy(5) {
}
Triangulo::~Triangulo() {}
// getters
int Triangulo::getLado() { return lado; }
// funciones
void Triangulo::Dibujar() {

}
void Triangulo::Mover() {
	posY += dy;
	if (posY < 0) {
		posY = 0;
		dy *= -1;
	}
	else if (posY + lado > limitY) {
		posY = limitY - lado;
		dy *= -1;
	}

}
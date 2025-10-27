#include "Triangulo.h"

Triangulo::Triangulo(int x, int y)
	: Figura(x, y, "Triangulo"), lado(20) {
	this->dy = 5;
	this->dx = 10;
}
Triangulo::~Triangulo() {}
// getters
int Triangulo::getLado() { return lado; }
// funciones
void Triangulo::Dibujar() {

}
void Triangulo::Mover() {
	dy += gravedad;
	posX += dx;
	posY += dy;
	if (posX < 0) {
		posX = 0;
		dx *= -1;
	}
	else if (posX + lado > limitX) {
		posX = limitX - lado;
		dx *= -1;
	}
	if (posY < 0) {
		posY = 0;
		dy *= -1;
	}
	else if (posY + lado > limitY) {
		posY = limitY - lado;
		dy *= -1;
	}
}
Rectangle Triangulo::getRectangle() {
	return Rectangle(posX, posY, lado, lado);
}
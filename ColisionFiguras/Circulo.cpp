#include "Circulo.h"

Circulo::Circulo(int x, int y)
: Figura(x,y, "Circulo"),diametro(30) {}
Circulo::~Circulo() {}
// getters
int Circulo::getDiametro() { return diametro; }
// funciones
void Circulo::Dibujar(){
	
}
void Circulo::Mover(){
	dy += gravedad;
	posX += dx;
	posY += dy;
	if (posX < 0) {
		posX = 0;
		dx *= -1;
	}
	else if (posX + diametro > limitX) {
		posX = limitX-diametro;
		dx *= -1;
	}
	if (posY < 0) {
		posY = 0;
		dy *= -1;
	}
	else if (posY + diametro > limitY) {
		posY = limitY - diametro;
		dy *= -1;
	}

}
Rectangle Circulo::getRectangle() {
	return Rectangle(posX, posY, diametro, diametro);
}
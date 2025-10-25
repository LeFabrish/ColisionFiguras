#include "Circulo.h"

Circulo::Circulo(int x, int y)
: Figura(x,y, "Circulo"),diametro(30), dx(5) {}
Circulo::~Circulo() {}
// getters
int Circulo::getDiametro() { return diametro; }
// funciones
void Circulo::Dibujar(){
	
}
void Circulo::Mover(){
	posX += dx;
	if (posX < 0) {
		posX = 0;
		dx *= -1;
	}
	else if (posX + diametro > limitX) {
		posX = limitX-diametro;
		dx *= -1;
	}

}
Rectangle Circulo::getRectangle() {
	return Rectangle(posX, posY, diametro, diametro);
}
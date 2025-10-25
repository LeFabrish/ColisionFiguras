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
bool Triangulo::colisionaCon(Figura* otra) {
    if (otra->getTipo() == "Circulo") {
        // Reutilizar la lógica del círculo (es simétrica)
        return otra->colisionaCon(this);
    }
    else if (otra->getTipo() == "Triangulo") {
        // Colisión triángulo con triángulo (usando rectángulos envolventes simplificado)
        Triangulo* otroTriangulo = (Triangulo*)otra;

        int x1 = posX;
        int y1 = posY;
        int w1 = lado;
        int h1 = lado;

        int x2 = otroTriangulo->getX();
        int y2 = otroTriangulo->getY();
        int w2 = otroTriangulo->getLado();
        int h2 = otroTriangulo->getLado();

        return !(x1 + w1 < x2 || x2 + w2 < x1 || y1 + h1 < y2 || y2 + h2 < y1);
    }
    return false;
}
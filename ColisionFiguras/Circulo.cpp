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
bool Circulo::colisionaCon(Figura* otra) {
    if (otra->getTipo() == "Circulo") {
        // Colisión círculo con círculo
        Circulo* otroCirculo = (Circulo*)otra;
        int radio1 = diametro / 2;
        int radio2 = otroCirculo->getDiametro() / 2;

        int centroX1 = posX + radio1;
        int centroY1 = posY + radio1;
        int centroX2 = otroCirculo->getX() + radio2;
        int centroY2 = otroCirculo->getY() + radio2;

        double distancia = sqrt(pow(centroX2 - centroX1, 2) + pow(centroY2 - centroY1, 2));

        return distancia < (radio1 + radio2);
    }
    else if (otra->getTipo() == "Triangulo") {
        // Colisión círculo con triángulo
        Triangulo* triangulo = (Triangulo*)otra;
        int radio = diametro / 2;
        int centroX = posX + radio;
        int centroY = posY + radio;

        // Vértices del triángulo
        int x1 = triangulo->getX();
        int y1 = triangulo->getY();
        int x2 = triangulo->getX();
        int y2 = triangulo->getY() + triangulo->getLado();
        int x3 = triangulo->getX() + triangulo->getLado();
        int y3 = triangulo->getY();

        // Verificar si el centro del círculo está cerca de algún vértice
        double dist1 = sqrt(pow(x1 - centroX, 2) + pow(y1 - centroY, 2));
        double dist2 = sqrt(pow(x2 - centroX, 2) + pow(y2 - centroY, 2));
        double dist3 = sqrt(pow(x3 - centroX, 2) + pow(y3 - centroY, 2));

        if (dist1 <= radio || dist2 <= radio || dist3 <= radio) {
            return true;
        }

        // Verificar si el centro está dentro del triángulo (método simple)
        // Usamos el área del triángulo
        int areaOriginal = abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2;
        int area1 = abs((x1 - centroX) * (y2 - centroY) - (x2 - centroX) * (y1 - centroY)) / 2;
        int area2 = abs((x2 - centroX) * (y3 - centroY) - (x3 - centroX) * (y2 - centroY)) / 2;
        int area3 = abs((x3 - centroX) * (y1 - centroY) - (x1 - centroX) * (y3 - centroY)) / 2;

        return (area1 + area2 + area3) <= areaOriginal + 5; // +5 tolerancia
    }
    return false;
}
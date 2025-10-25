#include "ControladorFiguras.h"

ControladorFiguras::ControladorFiguras() {}
ControladorFiguras::~ControladorFiguras(){}

void ControladorFiguras::agregarFigura(Figura* f){
	figuras.push_back(f);
}
void ControladorFiguras::moverFiguras(int lmtx, int lmty){
	for (auto f : figuras) {
		if (f->isVisible()) {
			f->setLimites(lmtx, lmty);
			f->Mover();
		}
	}
}
void ControladorFiguras::dibujarFiguras(Graphics^ g){
	for (auto f : figuras) {
		if (f->isVisible()) {
			Color color = Color::FromArgb(f->getR(), f->getG(), f->getB());
			SolidBrush^ broche = gcnew SolidBrush(color);
			if (f->getTipo() == "Circulo") {
				Circulo* c = (Circulo*)f;
				g->FillEllipse(broche,
					c->getX(), c->getY(),
					c->getDiametro(), c->getDiametro());
			}
			else if (f->getTipo() == "Triangulo") {
				Triangulo* t = (Triangulo*)f;

                cli::array<Point>^ puntos = gcnew cli::array<Point>(3);

				puntos[0] = Point(t->getX(), t->getY());
				puntos[1] = Point(t->getX(), t->getY()+ t->getLado());
				puntos[2] = Point(t->getX()+ t->getLado(), t->getY());

				g->FillPolygon(broche, puntos);
			}
		}
	}
}
void ControladorFiguras::verificarColisiones() {
	for (int i = 0; i < figuras.size(); i++) {
		if (!figuras[i]->isVisible()) continue;

		for (int j = i + 1; j < figuras.size(); j++) {
			if (!figuras[j]->isVisible()) continue;

			// Verificar si un círculo colisiona con un triángulo
			bool esCirculoTriangulo = (figuras[i]->getTipo() == "Circulo" && figuras[j]->getTipo() == "Triangulo");
			bool esTrianguloCirculo = (figuras[i]->getTipo() == "Triangulo" && figuras[j]->getTipo() == "Circulo");

			if (esCirculoTriangulo || esTrianguloCirculo) {
				if (figuras[i]->colisionaCon(figuras[j])) {
					// Hacer invisibles ambas figuras
					figuras[i]->setVisible(false);
					figuras[j]->setVisible(false);
				}
			}
		}
	}
}
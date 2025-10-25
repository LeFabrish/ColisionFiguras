#include "Figura.h"

Figura::Figura(int x, int y, string _tipo)
	: posX(x), posY(y), tipo(_tipo){
	this->visible = true;
	this->r = rand() % 256;
	this->g = rand() % 256;
	this->b = rand() % 256;
}
Figura::~Figura(){}
// getter y setters
int Figura::getX() { return posX; }
int Figura::getY() { return posY; }

int Figura::getR() { return r; }
int Figura::getG(){return g;}
int Figura::getB(){return b;}
string Figura::getTipo() { return tipo; }

void Figura::setVisible(bool v) { visible = v; }
bool Figura::isVisible() { return visible; }
void Figura::setLimites(int limitx, int limity){
	limitX = limitx;
	limitY = limity;
}
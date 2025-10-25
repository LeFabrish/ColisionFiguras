#pragma once
#include <string>
using namespace std;
class Figura
{
protected:
	int posX, posY,
		r, g, b;
	bool visible;
	string tipo;
	int limitX, limitY;
public:
	Figura(int x, int y, string tipo);
	~Figura();
	// getter y setters
	int getY();
	int getX();
	int getR();
	int getG();
	int getB();
	string getTipo();
	void setVisible(bool v);
	bool isVisible();
	void setLimites(int limitx, int limity);
	// virtuales
	virtual void Dibujar() = 0;
	virtual void Mover() = 0;
};


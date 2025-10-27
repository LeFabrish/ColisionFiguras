#pragma once
#include <string>
#include <cmath> 
using namespace std;
using namespace System::Drawing;
class Figura
{
protected:
	int posX, posY,
		r, g, b,
		dy, dx;
	bool visible;
	string tipo;
	int limitX, limitY;
	int gravedad;
public:
	Figura(int x, int y, string tipo);
	~Figura();
	// getter y setters
	int getY();
	int getX();
	int getR();
	int getG();
	int getB();

	int getDy();
	string getTipo();
	void setVisible(bool v);
	bool isVisible();
	void setLimites(int limitx, int limity);
	// virtuales
	virtual void Dibujar() = 0;
	virtual void Mover() = 0;
	virtual Rectangle getRectangle() = 0;
};


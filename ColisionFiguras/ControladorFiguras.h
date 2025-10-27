#pragma once
#include <vector>
#include "Figura.h"
#include "Circulo.h"
#include "Triangulo.h"
using namespace std;
using namespace System;
using namespace System::Drawing;
class ControladorFiguras
{
private: 
	vector<Figura*> figuras;
public:
	ControladorFiguras();
	~ControladorFiguras();
	void agregarFigura(Figura* f);
	void moverFiguras(int lmtx,int lmty);
	void dibujarFiguras(Graphics^ g);
	void verificarColisiones(); 
	Figura* obtenerFigura(int index);
};


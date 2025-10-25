#pragma once
#include "Figura.h"
#include "Circulo.h"
class Triangulo :
    public Figura
{
private:
    int lado;
    int dy;
public:
    Triangulo(int x, int y);
    ~Triangulo();
    // get
    int getLado();
    // funciones
    void Dibujar()override;
    void Mover()override;
    Rectangle getRectangle() override;
};


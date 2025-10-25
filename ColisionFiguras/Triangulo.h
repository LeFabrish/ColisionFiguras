#pragma once
#include "Figura.h"
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
    bool colisionaCon(Figura* otra) override;
};


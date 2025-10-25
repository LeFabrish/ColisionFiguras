#pragma once
#include "Figura.h"
#include "Triangulo.h"
class Circulo :
    public Figura
{
private:
    int diametro;
    int dx;
public:
    Circulo(int x, int y);
    ~Circulo();
    // getters
    int getDiametro();
    // funciones
    void Dibujar() override;
    void Mover() override;

    Rectangle getRectangle() override;
};


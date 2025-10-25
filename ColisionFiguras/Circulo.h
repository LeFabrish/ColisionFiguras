#pragma once
#include "Figura.h"
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
};


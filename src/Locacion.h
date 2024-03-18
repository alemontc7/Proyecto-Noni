#pragma once
#include "Mensaje.h"
class Locacion :
    public Mensaje
{
private:
    int x;
    int y;
public:
    Locacion(int id, string estado, int x, int y);
    ~Locacion();
    string toJson();
};


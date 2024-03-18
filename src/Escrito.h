#pragma once
#include "Estado.h"
class Escrito :
    public Estado
{
private:
    string contenido;
public:
    Escrito(int id, string horaDePublicacion, int duracion, string contenido);
    ~Escrito();
    string toJson();
};


#pragma once
#include "Estado.h"
class Imagen :
    public Estado
{
private:
    string nombre;
public:
    Imagen(int id,string horaDePublicacion, int duracion,string nombre);
    ~Imagen();
    string toJson();

};


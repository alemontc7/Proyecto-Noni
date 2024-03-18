#pragma once
#include "Mensaje.h"
class Archivo :
    public Mensaje
{
private:
    string nombre;
    string extension;
public:
    Archivo(int id, string estado, string nombre, string extension);
    ~Archivo();
    string toJson();
};


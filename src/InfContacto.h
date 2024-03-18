#pragma once
#include "Mensaje.h"
class InfContacto :
    public Mensaje
{
private:
    string contenido;
public:
    InfContacto(int id, string estado, string contenido);
    ~InfContacto();
    string getContenido();
    string toJson();
};


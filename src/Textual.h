#pragma once
#include "Mensaje.h"

class Textual :
    public Mensaje
{
private:
    string contenido;
public:
    Textual(int id,string esatdo,string contenido);
    ~Textual();
    string getContenido();
    string toJson();

};


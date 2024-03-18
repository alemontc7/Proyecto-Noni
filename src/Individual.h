#pragma once
#include "Chat.h"
#include "Usuario.h"

class Individual :
    public Chat
{
private:
    Usuario* receptor;
    Usuario* enviador;
public:
    Individual(string nombre, Usuario* receptor,Usuario* enviador);
    ~Individual();
    string toJson();
};


#pragma once
#include "Chat.h"
#include "Usuario.h"
#include "ModGen.h"
class Grupal :
    public Chat
{
private:
    ModGen<Usuario> participantes;
public:
    Grupal(string nombre);
    ~Grupal();
    ModGen<Usuario>* getParticipantes();
    string toJson();
    
};


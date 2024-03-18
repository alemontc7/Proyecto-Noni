#pragma once
#include "Llamada.h"
#include "Usuario.h"
class LIndividual :
    public Llamada
{
private:
    Usuario* solicitador;
    Usuario* receptor;
public:
    LIndividual(int id, string inicio, string fin, Usuario* solicitador, Usuario* receptor);
    ~LIndividual();
    string toJson();
    Usuario* getSolicitador();
    Usuario* getReceptor();
};


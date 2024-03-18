#pragma once
#include "Ayuda.h"
#include "Privacidad.h"
class Ajuste
{
private:
	int idAjuste; 	
	Ayuda* ayuda;
	Privacidad* privacidad;
public:
	Ajuste(int idAjuste,Ayuda* ayuda, Privacidad* privacidad);
	~Ajuste();
	string toJson();
	Privacidad* getPrivacidad();
};


#include "Ajuste.h"



Ajuste::Ajuste(int idAjuste, Ayuda* ayuda, Privacidad* privacidad)
{
	this->idAjuste = idAjuste;
	this->ayuda = ayuda;
	this->privacidad = privacidad;
}

Ajuste::~Ajuste()
{
}

string Ajuste::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Id ajuste\":" << idAjuste << ",";
	ss << "\"Ayuda\":" << ayuda->toJson() << ",";
	ss << "\"Privacidad\":" << privacidad->toJson();
	ss << "}";
	return ss.str();
}

Privacidad* Ajuste::getPrivacidad()
{
	return privacidad;
}

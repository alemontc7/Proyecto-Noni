#include "Camara.h"





Camara::Camara(int idCamara)
{
	this->idCamara = idCamara;
}

Camara::~Camara()
{
}

void Camara::mostrarMensaje()
{
	cout << "La foto fue tomada exitosamenete" << endl;
}

string Camara::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Id de la camara\":" << idCamara;
	ss << "}";
	return ss.str();
}

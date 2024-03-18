#include "Imagen.h"

Imagen::Imagen(int id, string horaDePublicacion, int duracion, string nombre):Estado(id,horaDePublicacion,duracion)
{
	this->nombre = nombre;
}

Imagen::~Imagen()
{
}

string Imagen::toJson()
{
	stringstream ss;
	ss << Estado::toJson();
	ss << "\"Nombre\":" << "\"" << nombre << "\"";
	ss << "}";
	return ss.str();
}

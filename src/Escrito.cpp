#include "Escrito.h"

Escrito::Escrito(int id, string horaDePublicacion, int duracion, string contenido):Estado(id,horaDePublicacion,duracion)
{
	this->contenido = contenido;
}

Escrito::~Escrito()
{
}

string Escrito::toJson()
{
	stringstream ss;
	ss << Estado::toJson();
	ss << "\"Contenido\":" << "\"" << contenido << "\"";
	ss << "}";
	return ss.str();
}

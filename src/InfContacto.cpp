#include "InfContacto.h"

InfContacto::InfContacto(int id, string estado, string contenido):Mensaje(id,estado)
{
	this->contenido = contenido;
}

InfContacto::~InfContacto()
{
}

string InfContacto::getContenido()
{
	return contenido;
}

string InfContacto::toJson()
{
	stringstream ss;
	ss << Mensaje::toJson();
	ss << "\"Contenido\":" << "\"" << contenido << "\"";
	ss << "}";
	return ss.str();
}

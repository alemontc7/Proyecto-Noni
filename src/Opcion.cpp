#include "Opcion.h"



Opcion::Opcion(int idOpcion, string contenidoOpcion)
{
	this->idOpcion = idOpcion;
	this->contenidoOpcion = contenidoOpcion;
}

Opcion::~Opcion()
{
}

string Opcion::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Id opcion\":" << idOpcion << ",";
	ss << "\"Contenido de la opcion\":" << "\"" << contenidoOpcion << "\"";
	ss << "}";
	return ss.str();
}

string Opcion::opcionToJson(Opcion* opcion)
{
	return opcion->toJson();;
}

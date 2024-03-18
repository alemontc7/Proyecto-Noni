#include "Archivo.h"

Archivo::Archivo(int id, string estado, string nombre, string extension):Mensaje(id,estado)
{
	this->nombre = nombre;
	this->extension = extension;
}

Archivo::~Archivo()
{
}

string Archivo::toJson()
{
	stringstream ss;
	ss << Mensaje::toJson();
	ss << "\"Nombre del archivo\":" << "\"" << nombre << "\"" << ",";
	ss << "\"Extension del archivo\":" << "\"" << extension << "\"";
	ss << "}";
	return ss.str();
}

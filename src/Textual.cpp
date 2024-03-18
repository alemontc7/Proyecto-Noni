#include "Textual.h"

Textual::Textual(int id,string estado,string contenido):Mensaje(id,estado)
{
	this->contenido = contenido;
}

Textual::~Textual()
{
}

string Textual::getContenido()
{
	return contenido;
}

string Textual::toJson()
{
	stringstream ss;
	ss << Mensaje::toJson();
	ss << "\"Contenido\":" << "\"" << contenido << "\"";
	ss << "}";
	return ss.str();
}

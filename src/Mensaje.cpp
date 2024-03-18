#include "Mensaje.h"

Mensaje::Mensaje(int id, string estado)
{
	this->id = id;
	this->estado = estado;
}

Mensaje::~Mensaje()
{
}

int Mensaje::getId()
{
	return id;
}

string Mensaje::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Id\":" << id << ",";
	return ss.str();
}

string Mensaje::mensajeToJson(Mensaje* mensaje)
{
	return mensaje->toJson();
}

#include "Locacion.h"

Locacion::Locacion(int id, string estado, int x, int y):Mensaje(id,estado)
{
	this->x = x;
	this->y = y;
}

Locacion::~Locacion()
{
}

string Locacion::toJson()
{
	stringstream ss;
	ss << Mensaje::toJson();
	ss << "\"Coordenada X\":" << x << ",";
	ss << "\"Coordenada Y\":" << y ;
	ss << "}";
	return ss.str();
}

#include "Estado.h"

Estado::Estado(int id, string horaDePublicacion,int duracion)
{
	this->id = id;
	this->horaDePublicacion = horaDePublicacion;
	this->duracion = duracion;
}

Estado::~Estado()
{
}

string Estado::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Id\":" << id << ",";
	ss << "\"Fecha de publicacion\":" << "\"" << horaDePublicacion << "\"" << ",";
	return ss.str();
}

string Estado::estadoToJson(Estado* estado)
{
	return estado->toJson();
}

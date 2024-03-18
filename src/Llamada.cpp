#include "Llamada.h"

Llamada::Llamada(int id, string inicio, string fin)
{
	this->id = id;
	this -> inicio = inicio;
	this->fin = fin;
	this->estado = "Pendiente";
}

Llamada::~Llamada()
{
}

string Llamada::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Id\":" << id << ",";
	ss << "\"Inicio de llamada\":" << "\"" << inicio << "\"" << ",";
	ss << "\"Fin de llamada\":" << "\"" << fin << "\"" << ",";
	ss << "\"Duracion de la llamada\":" << duracion << ",";
	ss << "\"Estado de la llamada\":" << "\"" << estado << "\"" << ",";
	return ss.str();
}

string Llamada::llamadaToJson(Llamada* llamada)
{
	return llamada->toJson();
}

void Llamada::setEstado(string estado)
{
	this->estado = estado;
}

string Llamada::getEstado()
{
	return estado;
}

void Llamada::setInicio(string inicio)
{
	this->inicio = inicio;
}

void Llamada::setFin(string fin)
{
	this->fin = fin;
}

void Llamada::setDuracion(int duracion)
{
	this->duracion = duracion;
}



#include "Individual.h"

Individual::Individual(string nombre, Usuario* receptor, Usuario* enviador):Chat(nombre)
{
	this->receptor = receptor;
	this->enviador = enviador;
}



Individual::~Individual()
{
}

string Individual::toJson()
{
	stringstream ss;
	ss << Chat::toJson();
	ss << "\"Receptor\":" << "\"" << receptor->getNombre()<<"\""<<",";
	ss << "\"Solicitador\":" << "\"" << enviador->getNombre() << "\"";
	ss << "}";
	return ss.str();
}

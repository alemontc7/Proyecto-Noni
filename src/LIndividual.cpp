#include "LIndividual.h"

LIndividual::LIndividual(int id, string inicio, string fin, Usuario* solicitador, Usuario* receptor):Llamada(id,inicio,fin)
{
	this->receptor = receptor;
	this->solicitador = solicitador;
}



LIndividual::~LIndividual()
{
}

string LIndividual::toJson()
{
	stringstream ss;
	ss << Llamada::toJson();
	ss << "\"Solicitador\":" << "\"" << solicitador->getNombre() << "\""<<",";
	ss << "\"Receptor\":" << "\"" << receptor->getNombre() << "\"";
	ss << "}";
	return ss.str();
}

Usuario* LIndividual::getSolicitador()
{
	return solicitador;
}

Usuario* LIndividual::getReceptor()
{
	return receptor;
}

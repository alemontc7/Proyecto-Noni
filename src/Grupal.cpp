#include "Grupal.h"

Grupal::Grupal(string nombre):Chat(nombre),participantes(256)
{
}

Grupal::~Grupal()
{
}

ModGen<Usuario>* Grupal::getParticipantes()
{
	return &participantes;
}

string Grupal::toJson()
{
	stringstream ss;
	ss << Chat::toJson();
	ss << "\"Participantes del chat\":";
	ss << "[";
	for (int i = 0; i < participantes.getInd(); i++)
	{
		ss << "\"";
		ss << participantes.getPuntero(i)->getNombre();
		ss << "\"";
		if (i < participantes.getInd()-1)
		{
			ss << ",";
		}

		
	}
	ss << "]";
	ss << "}";
	return ss.str();
}

#pragma once
#include "Mensaje.h"
#include "ModGen.h"

class Chat
{
protected:
	string nombre;
	ModGen<Mensaje> mensajes;
public:
	Chat(string nombre);
	~Chat();
	ModGen<Mensaje>* getModMensajes();
	virtual string toJson();
	static string chatToJson(Chat* chat);
	bool operator==(Chat* chat);
};


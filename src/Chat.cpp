#include "Chat.h"

Chat::Chat(string nombre):mensajes(10000)
{
	
	this->nombre = nombre;
}

Chat::~Chat()
{
}

ModGen<Mensaje>* Chat::getModMensajes()
{
	return &mensajes;
}

string Chat::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Nombre\":" << "\""<<nombre<<"\"" << ",";
	ss << "\"Mensajes\":" << mensajes.toJson(Mensaje::mensajeToJson) << ",";
	return ss.str();
}

string Chat::chatToJson(Chat* chat)
{
	return chat->toJson();
}

bool Chat::operator==(Chat* chat)
{
	return nombre==chat->nombre;
}

#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class Mensaje
{
protected:
	int id;
	string estado;//Hace referencia a no enviado, entregado y visto
public:
	Mensaje(int id, string estado);
	~Mensaje();
	int getId();
	virtual string toJson();
	static string mensajeToJson(Mensaje* mensaje);
};


#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Llamada
{
protected:
	int id;
	string inicio;
	string fin;
	string estado;
	int duracion;
public:
	Llamada(int id, string inicio, string fin);
	~Llamada();
	virtual string toJson();
	static string llamadaToJson(Llamada* llamada);
	void setEstado(string estado);
	string getEstado();
	void setInicio(string inicio);
	void setFin(string fin);
	void setDuracion(int duracion);
};


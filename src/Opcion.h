#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Opcion
{
private:
	int idOpcion;
	string contenidoOpcion;
public:
	Opcion(int idOpcion,string contenidoOpcion);
	~Opcion();
	string toJson();
	static string opcionToJson(Opcion* opcion);
};


#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Camara
{
private:
	int idCamara;
public:
	Camara(int idCamara);
	~Camara();
	void mostrarMensaje();
	string toJson();
};


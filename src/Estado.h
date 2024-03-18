#pragma once
#include <iostream>
using namespace std;
#include <sstream>
#include <string>


class Estado
{
protected:
	int id;
	string horaDePublicacion;
	int duracion;
	
public:
	Estado(int id, string horaDePublicacion,int duracion);
	~Estado();
	virtual string toJson();
	static string estadoToJson(Estado* estado);
	

};


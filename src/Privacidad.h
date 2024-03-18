#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Privacidad
{
private:
	int id;
	string horaUltimaVez;
	string visualizacionDeFoto;
	string visualizacionDeInfo;
public:
	Privacidad(int id,string horaUltimaVez, string visualizacionDeFoto, string visualizacionDeInfo);
	~Privacidad();
	void setHoraUltimaVez(string horaUltimaVez);
	void setVisualizacionDeFoto(string visualizacionDeFoto);
	void setVisualizacionDeInfo(string visualizacionDeInfo);
	string toJson();
	string getHoraUltimaVez();
	string getVisualizacionInfo();
	string getVisualizacionDeFoto();
	
};


#include "Privacidad.h"

Privacidad::Privacidad(int id, string horaUltimaVez, string visualizacionDeFoto, string visualizacionDeInfo)
{
	this->id = id;
	this->horaUltimaVez = horaUltimaVez;
	this->visualizacionDeFoto = visualizacionDeFoto;
	this->visualizacionDeInfo = visualizacionDeInfo;
}

Privacidad::~Privacidad()
{
}

void Privacidad::setHoraUltimaVez(string horaUltimaVez)
{
	this->horaUltimaVez = horaUltimaVez;
	
}

void Privacidad::setVisualizacionDeFoto(string visualizacionDeFoto)
{
	
	this->visualizacionDeFoto = visualizacionDeFoto;
	
}

void Privacidad::setVisualizacionDeInfo(string visualizacionDeInfo)
{
	
	this->visualizacionDeInfo = visualizacionDeInfo;
}

string Privacidad::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Id\":" << id << ",";
	ss << "\"Hora de ultima vez\":" << "\"" << horaUltimaVez << "\"" << ",";
	ss << "\"Foto\":" << "\"" << visualizacionDeFoto << "\"" << ",";
	ss << "\"Info\":" << "\"" << visualizacionDeInfo << "\"" ;
	ss << "}";
	return ss.str();
}

string Privacidad::getHoraUltimaVez()
{
	return horaUltimaVez;
}

string Privacidad::getVisualizacionInfo()
{
	return visualizacionDeInfo;
}

string Privacidad::getVisualizacionDeFoto()
{
	return visualizacionDeFoto;
}



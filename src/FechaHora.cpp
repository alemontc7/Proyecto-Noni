#include "FechaHora.h"

FechaHora::FechaHora()
{
	
	dia_semana[0]="Domingo";
	dia_semana[1] = "Lunes";
	dia_semana[2] = "Martes";
	dia_semana[3] = "Miercoles";
	dia_semana[4] = "Jueves";
	dia_semana[5] = "Viernes";
	dia_semana[6] = "Sabado";

	
	mes[0] = "Enero";
	mes[1] = "Febrero";
	mes[2] = "Marzo";
	mes[3] = "Abril";
	mes[4] = "Mayo";
	mes[5] = "Junio";
	mes[6] = "Julio";
	mes[7] = "Agosto";
	mes[8] = "Septiembre";
	mes[9] = "Octubre";
	mes[10] = "Noviembre";
	mes[11] = "Diciembre";
}

FechaHora::~FechaHora()
{
}

string FechaHora::muestraFechaEnNums()
{
	/* fecha/hora actual basado en el sistema actual */
	time_t now = time(0);

	/* Objeto de una estructura tm con fecha/hora local */
	tm* time = localtime(&now);

	stringstream ss;

	int year = 1900 + time->tm_year;

	
	ss << time->tm_mday << "/" << time->tm_mon+1 << "/" << year;
	return ss.str();

}

string FechaHora::muestraFechaCompletaEnCadena()
{
	/* fecha/hora actual basado en el sistema actual */
	time_t now = time(0);

	/* Objeto de una estructura tm con fecha/hora local */
	tm* time = localtime(&now);
	int year = 1900 + time->tm_year;

	//Formato=hoy miercoles, 27 de mayo del 2015
	stringstream ss;
	ss << dia_semana[time->tm_wday];
	ss << time->tm_mday << " de " << mes[time->tm_mon] << " del " << year;
	return ss.str();
}

string FechaHora::muestraHora()
{
	time_t now = time(0);
	tm* time = localtime(&now);
	stringstream ss;
	ss << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec;
	return ss.str();
}


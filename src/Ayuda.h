#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Ayuda
{
private:
	int id;
	string contenido;
public:
	Ayuda(int id);
	~Ayuda();
	string toJson();
	static void mensajeParaNombreNoValido();
	static void mensajeParaNumeroNoValido();
	//static void mensajeParaInfoNoValida();
	static void mensajeParaOpcionNoValida();
	static void menuDeAyuda();
	static void menuDeActividadesDeUsuario();
	static void menuCuentas();
	static void menuTiposDeEstado();
	static void aceptarRechazarVolverAlMenu();
	static void menuTiposDeMensaje();
};


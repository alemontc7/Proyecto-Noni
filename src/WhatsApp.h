#pragma once
#include "SingletonUsuarios.h"
#include "Ayuda.h"
#include "Privacidad.h"
#include "Usuario.h"
#include "Validador.h"
class WhatsApp
{
private:
	string nombre;

public:
	static int idAyuda;
	static int idPrivacidad;
	static int idAjuste;
	static int idCamara;
	WhatsApp(string nombre);
	~WhatsApp();
	ModGen<Usuario>* getUsuarios();
	string toJson();
	void registrarUsuario();
	void hacerActividades(Usuario* usuario);
	void entrarSalirCuentas();

};


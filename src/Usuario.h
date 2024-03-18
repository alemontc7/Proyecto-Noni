#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Llamada.h"
//#include "ModGen.h"
#include "Chat.h"
#include "Ajuste.h"
#include "Camara.h"

#include "Estado.h"

	class Usuario
	{
	private:
		string fono;
		string nombre;
		string info;
		string horaUltimaVez;
		string foto;
		Ajuste* ajuste;
		
		Camara* camara;
		ModGen<Llamada> llamadas;
		ModGen<Chat> chats;
		ModGen<Usuario> contactos;
		ModGen<Estado> estados;
	public:
		Usuario(string fono, string nombre, string info, Ajuste* ajuste, Camara* camara,string foto);
		Usuario(string fono);
		~Usuario();
		string toJson();
		string toJsonSoloNum();
		static string usuarioToJson(Usuario* usuario);
		static string usuarioToJsonSoloNum(Usuario* usuario);
		ModGen<Chat>* getModChats();
		ModGen<Llamada>* getModLlamadas();
		ModGen<Usuario>* getModContactos();
		ModGen<Estado>* getModEstados();
		bool operator==(Usuario* u);
		string getNombre();
		void setHoraUltimaVez(string horaUltimaVez);
		Ajuste* getAjuste();
		string getHoraUltimaVez();
		string getFotoDePerfil();
		string getInfo();
		string getInfoDeContactoParaEnviar();

	};
	


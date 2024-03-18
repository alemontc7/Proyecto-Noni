#pragma once
#include "ModGen.h"
#include "Usuario.h"
#include "Validador.h"
#include "FechaHora.h"
#include "Imagen.h"
#include "Escrito.h"
#include "LIndividual.h"
#include "Individual.h"
#include "Grupal.h"
#include "Textual.h"
#include "Archivo.h"
#include "InfContacto.h"
#include "Locacion.h"
#include "Encuesta.h"
class SingletonUsuarios
{
private:

	ModGen<Usuario> usuarios;
public:
	static int idEstado;
	static int idLlamada;
	static int idMensaje;
	
	static SingletonUsuarios& obtenerInstancia();
	~SingletonUsuarios();
	ModGen<Usuario>* getModUsuarios();
	void registrarContactoParaUsuario(Usuario* usuario);
	void registrarEstadoParaUsuario(Usuario* usuario);
	void realizarLlamadaSimple(Usuario* usuario);
	void verLlamadaEntrante(Usuario* usuario);//Esto solo lo debe poder hacer el receptor
	void colgarLlamadaAunNoContestadaPorOtroUsuario(Usuario* usuario);//Esto solo lo debe poder hacer el solicitador
	void volver_A_LlamadaContestada(Usuario* usuario);//esto lo deben poder hacer ambos
	void verPerfilDeUnUsuario(Usuario* usuario);
	void crearChatIndividualConUnUsuario(Usuario* usuario);
	void crearChatGrupal(Usuario* usuario);
	void aniadirParticipanteChatGrupal(Usuario* usuario);
	void enviarMensajeChat(Usuario* usuario);//A caulquier tipo de chat
	void verMensajesDeCiertoChat(Usuario* usuario);//De cualquier tipo de chat
	void usarCamara(Usuario* usuario);
private:
	SingletonUsuarios();
};


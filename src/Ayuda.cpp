#include "Ayuda.h"





Ayuda::Ayuda(int id)
{
	this->contenido = "Contacta nuestro gmail whatsapp@gmail.com";
	this->id = id;
}

Ayuda::~Ayuda()
{
}

string Ayuda::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Id ayuda\":" << id << ",";
	ss << "\"Contenido\":" << "\"" << contenido << "\"";
	ss << "}";
	return ss.str();
}

void Ayuda::mensajeParaNombreNoValido()
{
	cout << "\n";
	cout << "Porfavor ingrese un nombre correcto compuesto solo de caracteres alfabeticos o numeros" << endl;
}

void Ayuda::mensajeParaNumeroNoValido()
{
	cout << "\n";
	cout << "Porfavor ingrese un numero que si sea correcto" << endl;
}

void Ayuda::mensajeParaOpcionNoValida()
{
	cout << "\n";
	cout << "Porfavor ingrese una opcion que si sea correcto" << endl;
}

void Ayuda::menuDeAyuda()
{
	cout << "1-. Todos" << endl;
	cout << "2-. Mis contactos" << endl;
	cout << "3-.Nadie" << endl;
}

void Ayuda::menuDeActividadesDeUsuario()
{
	cout << "1-. Registrar un contacto" << endl;
	cout << "2-. Crear un estado en whatsapp" << endl;
	cout << "3-. Realizar una llamada" << endl;
	cout << "4-. Colgar llamada aun no contestada por otro usuario" << endl;
	cout << "5-. Ver llamada entrante" << endl;
	cout << "6-. Volver a llamada contestada" << endl;
	cout << "7-. Ver el perfil de algun usuario" << endl;
	cout << "8-. Crear un chat individual" << endl;
	cout << "9-.Crear un chat grupal" << endl;
	cout << "10-. Aniadir un participante a algun chat grupal" << endl;
	cout << "11-. Enviar mensaje a algun chat" << endl;//cualquier tipo de chat
	cout << "12-. Ver mensajes de algun chat" << endl;//cualquier tipo de chat
	cout << "13-. Usar camara" << endl;
	cout << "14-. Salir de mi cuenta" << endl;
}

void Ayuda::menuCuentas()
{
	cout << "1-. Iniciar sesion" << endl;
	cout << "2-. Registrar un usuario de whatsapp" << endl;
	cout << "3-. Salir de whatsapp" << endl;
}

void Ayuda::menuTiposDeEstado()
{
	cout << "1-. Imagen" << endl;
	cout << "2-.Escrito" << endl;
}

void Ayuda::aceptarRechazarVolverAlMenu()
{
	cout << "1-. Aceptar llamada" << endl;
	cout << "2-. Rechazar llamada" << endl;
	cout << "3-. Volver al menu" << endl;
}

void Ayuda::menuTiposDeMensaje()
{
	cout << "1-. Textual" << endl;
	cout << "2-. Archivo" << endl;
	cout << "3-. Contacto" << endl;
	cout << "4-. Locacion" << endl;
	cout << "5-. Encuesta" << endl;
}



//void Ayuda::mensajeParaInfoNoValida()
//{
//	cout << "\n";
//	cout << "Porfavor ingrese una informacion de usuario correcta compuesto solo de caracteres alfabeticos o numeros" << endl;
//}





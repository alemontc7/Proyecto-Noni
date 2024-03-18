#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
//Una clase generica tiene un atributo el cual sera parametrizado
//Eliminamos el cpp de clases genericas
template <class T>

class ModGen
{
private:
	int tamMax;
	int ind;
	T** datos;
public:
	ModGen(int tamMax);
	~ModGen();
	void deletePorComposicion();
	void registrar(T* dato);
	T* buscar(T* dato);
	string toJson(string(*funcJson)(T*));
	void mostrar(string(*funcJson)(T*));
	void ordenar(bool(*funcOrdenAsc)(T*, T*));
	int getInd();
	T* getPuntero(int i);
	T* operator[](int i);
	int obtenerPosEliminar(T* dato);
	void eliminarRegistro(T* dato);
	//T* buscar(string dato);
	/*void registrar(string dato);
	string toString();*/



};

template<class T>//Vuelve a crear un template  porque nos acabamos de salir de la clase ModGen
ModGen<T>::ModGen(int tamMax)//esta linea dice de la clase ModGen definime un metodo que tiene de nombre
//la misma clase osea es el constructor
{
	this->tamMax = tamMax;
	ind = 0;
	datos = new T * [tamMax];

}

template<class T>
ModGen<T>::~ModGen()
{

	delete[] datos;
}

template<class T>
void ModGen<T>::deletePorComposicion()
{
	for (int i = 0; i < ind; i++)
	{
		delete datos[i];
	}
}

template<class T>
void ModGen<T>::registrar(T* dato)
{
	if (ind < tamMax)
	{
		datos[ind] = dato;
		ind++;
	}
}





template<class T>
string ModGen<T>::toJson(string(*funcJson)(T*))
{
	stringstream ss;
	/*ss << "{";
	ss << "\"tamMax\":" << tamMax << ",";
	ss << "\"ind\":" << ind << ",";
	ss << "\"datos\":";*/
	ss << "[";

	for (int i = 0; i < ind; i++)
	{
		ss << (*funcJson)(datos[i]);//debo poner persona es una clase generica aqui no se conoce personas
		//aca debo generar un json pero de acuerdo al tipo de dato que tiene almacenado el modulo
		//el modulo no conoce el tipo de dato, entonce el modulo no sabe como generar el json del
		//dato que se encunetra amacenado en la posicion [i] tengo que decirle al modulo
		//converti los datos a json de esta manera, lo que debo usar que esta fuera de la clase
		//lo parametrizo, debo enviar como parametro al toJson() la funcion que me permite transformar
		// a json el dato 
		if (i < ind - 1)
		{
			ss << ",";
		}
	}

	ss << "]";
	//ss << "}";
	return ss.str();
}

template<class T>
void ModGen<T>::mostrar(string(*funcJson)(T*))
{
	cout << toJson(funcJson) << endl;
}

template<class T>
void ModGen<T>::ordenar(bool(*funcOrdenAsc)(T*, T*))
{
	T* aux;
	for (int i = 0; i < ind - 1; i++)
	{
		for (int j = i + 1; j < ind; j++)
		{
			if ((*funcOrdenAsc)(datos[i], datos[j]))
			{
				aux = datos[i];
				datos[i] = datos[j];
				datos[j] = aux;
			}
		}
	}
}
template<class T>
int ModGen<T>::getInd()
{
	return ind;
}
template<class T>
T* ModGen<T>::getPuntero(int i)
{
	return datos[i];
}
template<class T>
inline T* ModGen<T>::operator[](int i)
{
	return datos[i];
}
template<class T>
int ModGen<T>::obtenerPosEliminar(T* dato)
{
	for (int i = 0; i < ind; i++)
	{
		if (*datos[i] == dato)
		{
			return i;
		}
	}
	return -1;
}
template<class T>
void ModGen<T>::eliminarRegistro(T* dato)
{
	if (obtenerPosEliminar(dato) >= 0)
	{
		for (int i = obtenerPosEliminar(dato); i < ind - 1; i++)
		{
			datos[i] = datos[i + 1];
		}
		ind = ind - 1;
	}
	else
	{
		cout << "No se encuentra el registro que trata de eliminar" << endl;
	}

}
//template<class T>
//T* ModGen<T>::buscar(string dato)
//{
//	for (int i = 0; i < ind; i++)
//	{
//		if (*(datos[i]) == dato)//Aqui pensaste en hacer una comparacion de puntero osea que me llegue como argumento un 
//			//puntero a un objeto y lo comparas con el puntero de la izquierda, asi no era necesario el operator
//			//pero el docuente quiere que si o si comparws objetos y no punteros
//		{
//			return datos[i];
//		}
//	}
//	return NULL;
//}
//template<class T>
//#include "Singleton.h"
//void ModGen<T>::registrar(string dato)
//{
//	/*T* (*funcObInstancia)(string dato);
//	T* punteroT = punteroEquipo;*/
//	T* punteroT = Singleton::obtenerInstancia().obtenerInstanciaEquipo(dato);
//	if (ind < tamMax)
//	{
//		datos[ind] = punteroT;
//		ind++;
//	}
//}
//
//template<class T>
//string ModGen<T>::toString()
//{
//	return "xdd";
//}

template<class T>
T* ModGen<T>::buscar(T* dato)
{
	for (int i = 0; i < ind; i++)
	{
		if (*(datos[i]) == dato)//Aqui pensaste en hacer una comparacion de puntero osea que me llegue como argumento un 
			//puntero a un objeto y lo comparas con el puntero de la izquierda, asi no era necesario el operator
			//pero el docuente quiere que si o si comparws objetos y no punteros
		{
			return datos[i];
		}
	}
	return NULL;
}

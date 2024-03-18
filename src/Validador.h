#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
using namespace std;
class Validador
{
private:
	int idValidador;
public:
    static bool opcionValida(char num);
    static char obligarAlUsuarioAPonerOpcionValida();
    static bool validarCadena(string cadena);
    static void obligarAlUsuarioPonerCadenaValida(string& cadena);
    static bool validarSiUnaCadenaEsUnNum(string num);
    static void obligarAlUsuarioPonerCadenaValidaDeNums(string& cadena);
    static void capturarPosibleExcepcionDeNumNoValido(string& numContactoAmigo);

};


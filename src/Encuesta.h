#pragma once
#include "Mensaje.h"
#include "Opcion.h"
#include "ModGen.h"
class Encuesta :
    public Mensaje
{
private:
    int idEncuesta;
    ModGen<Opcion> opciones;
    string pregunta;
    string respuesta;
public:
    static int idOpcion;
    Encuesta(int idEncuesta, string pregunta);
    ~Encuesta();
    ModGen<Opcion>* getModOpciones();
    void agregarPregunta(string pregunta);
    string toJson();
};


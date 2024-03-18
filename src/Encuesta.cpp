#include "Encuesta.h"
int Encuesta::idOpcion;
Encuesta::Encuesta(int idEncuesta, string pregunta):opciones(100),Mensaje(idEncuesta,"Entregado")
{
    idOpcion = 0;
    this->pregunta = pregunta;
}

Encuesta::~Encuesta()
{
}

ModGen<Opcion>* Encuesta::getModOpciones()
{
    return &opciones;
}

void Encuesta::agregarPregunta(string pregunta)
{
    opciones.registrar(new Opcion(idOpcion, pregunta));
    idOpcion++;
}

string Encuesta::toJson()
{
    stringstream ss;
    ss << "{";
    ss << "\"Id encuesta\":" << idEncuesta << ",";
    ss << "\"Pregunta\":" <<"\""<<pregunta << "\""<<",";
    ss << "\"Opciones\":" << opciones.toJson(Opcion::opcionToJson);
    ss << "}";
    return ss.str();
}

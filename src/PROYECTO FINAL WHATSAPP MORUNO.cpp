

#include <iostream>
#include <sstream>
#include <string>
#include "WhatsApp.h"
#include "FechaHora.h"
using namespace std;
int main()
{
    WhatsApp  whatsapp("WhatssApp");

    whatsapp.entrarSalirCuentas();
    cout << whatsapp.toJson();
    /*FechaHora::mostrarFecha();*/
   /* FechaHora* fh=new FechaHora();
    cout<<fh->muestraFechaEnCadena()<<endl;
    cout << fh->muestraFechaEnNums() << endl;
    cout << fh->muestraHora() << endl;*/
}


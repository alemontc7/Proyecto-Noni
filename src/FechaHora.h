
#pragma once

#include <iostream>

#include <ctime>
#include <vector>
#include <stdio.h>

#include <time.h>
using namespace std;
#include <stdio.h>

#include <time.h>
#include <sstream>


class FechaHora
{
private:
	string mes[12];
	string dia_semana[7];
public:
	FechaHora();
	~FechaHora();
	string muestraFechaEnNums();
	string muestraFechaCompletaEnCadena();
	string muestraHora();


};


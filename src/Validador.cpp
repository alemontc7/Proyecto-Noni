#include "Validador.h"
#include"Ayuda.h"
bool Validador::opcionValida(char num)
{
    bool EsNum = false;

    if (num=='1' || num=='2' || num=='3')
    {
        EsNum = true;
        return EsNum;
    }
    else
    {
        return EsNum;

    }
}

char Validador::obligarAlUsuarioAPonerOpcionValida()
{
    char num;
    bool noEsNum = true;
    cin.ignore();
    cin >> num;
    while (noEsNum) {
        if (num == '1' || num == '2' || num == '3')
        {
            noEsNum = false;

        }
        else
        {
            cout << "Porfavor ingrese un numero valido" << endl;
            cin >> num;

        }
    }
    return num;
}

bool Validador::validarCadena(string cadena)
{
    //El nombre solo permitira numero y letras whatsapp permite ponerte de nombre lo que tu quieras pero es mi aplicacion y la puedo hacer mas compleja
    char c;
    bool CadenaValida = false;
    /*int num;*/

    for (int i = 0; i < cadena.size(); i++)
    {
        c = cadena[i];

        if (isalpha(c)!=0 || isdigit(c) != 0 || c==' ')//la funcion is digit devuelve cero si un caracter no es un digito y en caso serlo devuelve algo !=0
        {//la funcion is alpha devuelve algo distinto a cero si el caracter esta entre A-Z y a-z y devuelve 0 si no cae en ello
            CadenaValida = true;
        }
        else
        {
            
            CadenaValida = false;
            break;
        }

    }
    return CadenaValida;
}

void Validador::obligarAlUsuarioPonerCadenaValida(string& cadena)
{
    char c;
    bool noEsCadenaValida = true;
    /*int num;*/
    cin >> cadena;
    while (noEsCadenaValida)
    {
        for (int i = 0; i < cadena.size(); i++)
        {
            c = cadena[i];

            if (isalpha(c)!=0  || isdigit(c) != 0 || c == ' ')
            {
                noEsCadenaValida = false;
            }
            else

            {
                Ayuda::mensajeParaNombreNoValido();
                cin >> cadena;
                noEsCadenaValida = true;
                break;
            }

        }



    }
}

bool Validador::validarSiUnaCadenaEsUnNum(string num)
{
    char c;
    bool numValido = false;
    for (int i = 0; i < num.size(); i++)
    {
        c = num[i];

        if (isdigit(c)!=0)
        {
            numValido = true;

        }
        else
        {
            numValido = false;
            break;
        }

    }
    return numValido;
}

void Validador::obligarAlUsuarioPonerCadenaValidaDeNums(string& cadena)
{
    char c;
    bool noEsCadenaValida = true;
    //int num;
    cin >> cadena;
    while (noEsCadenaValida)
    {
        for (int i = 0; i < cadena.size(); i++)
        {
            c = cadena[i];

            if (isdigit(c )!=0)
            {
                noEsCadenaValida = false;
            }
            else
            {
                Ayuda::mensajeParaNumeroNoValido();
                cin >> cadena;
                noEsCadenaValida = true;
                break;
            }

        }
    }
}

void Validador::capturarPosibleExcepcionDeNumNoValido(string& numContactoAmigo)
{
    //cout << "Digame el numero de telefono del usuario sobre el cual quiere realizar operaciones" << endl;
    try
    {
        cin >> numContactoAmigo;
        if (Validador::validarSiUnaCadenaEsUnNum(numContactoAmigo) == false)
        {

            throw exception("Numero de telefono no valido");
        }
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
        Ayuda::mensajeParaNumeroNoValido();
        Validador::obligarAlUsuarioPonerCadenaValidaDeNums(numContactoAmigo);
    }

}



#include "WhatsApp.h"
int WhatsApp::idAyuda;
int WhatsApp::idAjuste;

int WhatsApp::idCamara;
int WhatsApp::idPrivacidad;
WhatsApp::WhatsApp(string nombre)
{
    this->nombre = nombre;
    idAyuda = 0;
    idPrivacidad = 0;
    idAjuste = 0;
    idCamara = 0;
}

WhatsApp::~WhatsApp()
{
}
string WhatsApp::toJson()
{
    stringstream ss;
    ss << "{";
    ss << "\"Nombre\":" << "\"" << nombre << "\"" << ",";
    ss << "\"Usuarios:\":" << SingletonUsuarios::obtenerInstancia().getModUsuarios()->toJson(Usuario::usuarioToJson);
    ss << "}";
    return ss.str();
}
ModGen<Usuario>* WhatsApp::getUsuarios()
{
    return SingletonUsuarios::obtenerInstancia().getModUsuarios();
}

void WhatsApp::registrarUsuario()
{
    string fono;
    string nombre;
    string info;
    string foto;
    char opcion;
    string horaUltimaVez;
    string visualizacionFoto;
    string visualizacionInfo;
    cout << "Introduzca su numero de celular" << endl;
   /* try
    {
        cin >> fono;
        if (Validador::validarSiUnaCadenaEsUnNum(fono) == false)
        {
            throw exception("El numero que ingreso no es valido");
        }
    }
    catch (exception& e)
    {
        cout << e.what();
        Ayuda::mensajeParaNumeroNoValido();
        Validador::obligarAlUsuarioPonerCadenaValidaDeNums(fono);
    }*/
    Validador::capturarPosibleExcepcionDeNumNoValido(fono);
    cout << "Introduzca el nombre con el que lo veran los otros usuarios" << endl;
    try
    {
        cin.ignore();
        getline(cin, nombre);
        if (Validador::validarCadena(nombre) == false)
        {
            throw exception("El nombre que ingreso no es valido");
        }
    }
    catch (exception& e)
    {
        cout << e.what();
        Ayuda::mensajeParaNombreNoValido();
        Validador::obligarAlUsuarioPonerCadenaValida(nombre);
    }
    cout << "Introduzca la informacion de usuario que aparecera en su perfil" << endl;
    //cin.ignore(); no es neceario pues previo a este ya se hizo un cin.ignore
    getline(cin, info);
    //La info de usuario acepta cualquier caracter
    cout << "Introduzca el nombre de la foto de su galeria que escogera como perfil" << endl;
    //cin.ignore();
    getline(cin, foto);
    foto = foto+"png";
    cout << "Quien puede ver mi ultima vez?" << endl;
    Ayuda::menuDeAyuda();
    try
    {
        cin >> opcion;
        if (Validador::opcionValida(opcion) == false)
        {
            throw exception("La opcion que ingreso no es valida");
        }
    }
    catch (exception& e)
    {
        cout << e.what();
        Ayuda::mensajeParaOpcionNoValida();
        opcion = Validador::obligarAlUsuarioAPonerOpcionValida();
    }
    if (opcion == '1')
    {
        horaUltimaVez = "Todos";
    }
    if (opcion == '2')
    {
        horaUltimaVez = "Mis contactos";
    }
    if (opcion == '3')
    {
        horaUltimaVez = "Nadie";
    }



    cout << "Quien puede ver mi informacion?" << endl;
    Ayuda::menuDeAyuda();
    try
    {
        cin >> opcion;
        if (Validador::opcionValida(opcion) == false)
        {
            throw exception("La opcion que ingreso no es valida");
        }
    }
    catch (exception& e)
    {
        cout << e.what();
        Ayuda::mensajeParaOpcionNoValida();
        opcion = Validador::obligarAlUsuarioAPonerOpcionValida();
    }

    if (opcion == '1')
    {
        visualizacionInfo = "Todos";
    }
    if (opcion == '2')
    {
        visualizacionInfo = "Mis contactos";
    }
    if (opcion == '3')
    {
        visualizacionInfo = "Nadie";
    }



    cout << "Quien puede ver mi foto perfil?" << endl;

    Ayuda::menuDeAyuda();
    try
    {
        cin >> opcion;
        if (Validador::opcionValida(opcion) == false)
        {
            throw exception("La opcion que ingreso no es valida");
        }
    }
    catch (exception& e)
    {
        cout << e.what();
        Ayuda::mensajeParaOpcionNoValida();
        opcion = Validador::obligarAlUsuarioAPonerOpcionValida();
    }
    if (opcion == '1')
    {
        visualizacionFoto = "Todos";
    }
    if (opcion == '2')
    {
        visualizacionFoto = "Mis contactos";
    }
    if (opcion == '3')
    {
        visualizacionFoto = "Nadie";
    }





    Ayuda* ayuda = new Ayuda(idAyuda);
    idAyuda++;
    Privacidad* privacidad = new Privacidad(idPrivacidad, horaUltimaVez, visualizacionFoto, visualizacionInfo);
    idPrivacidad++;
    Ajuste* ajuste = new Ajuste(idAjuste, ayuda, privacidad);
    idAjuste++;
    
    Camara* camara = new Camara(idCamara);
    idCamara++;
    Usuario* usuario = new Usuario(fono, nombre, info, ajuste, camara,foto);
    SingletonUsuarios::obtenerInstancia().getModUsuarios()->registrar(usuario);
    cout << "Iniciado sesion" << endl;
    system("pause");
    system("cls");
    hacerActividades(usuario);

}



void WhatsApp::hacerActividades(Usuario* usuario)
{
    FechaHora fecha;
    int opcion;
    bool seguir = true;
    while (seguir)
    {
        Ayuda::menuDeActividadesDeUsuario();
        cin >> opcion;
        system("pause");
        system("cls");
        if (opcion == 1)
        {
            
            SingletonUsuarios::obtenerInstancia().registrarContactoParaUsuario(usuario);
            system("pause");
            system("cls");
        }
        if (opcion == 2)
        {
            SingletonUsuarios::obtenerInstancia().registrarEstadoParaUsuario(usuario);
            system("pause");
            system("cls");
        }
        if (opcion == 3)
        {
            SingletonUsuarios::obtenerInstancia().realizarLlamadaSimple(usuario);
        }
        if (opcion == 4)
        {
            SingletonUsuarios::obtenerInstancia().colgarLlamadaAunNoContestadaPorOtroUsuario(usuario);
        }
        if (opcion == 5)
        {
            SingletonUsuarios::obtenerInstancia().verLlamadaEntrante(usuario);
        }
        if (opcion == 6)
        {
            SingletonUsuarios::obtenerInstancia().volver_A_LlamadaContestada(usuario);
        }
        if (opcion == 7)
        {
            SingletonUsuarios::obtenerInstancia().verPerfilDeUnUsuario(usuario);
        }
        if (opcion == 8)
        {
            SingletonUsuarios::obtenerInstancia().crearChatIndividualConUnUsuario(usuario);
        }
        if (opcion == 9)
        {
            SingletonUsuarios::obtenerInstancia().crearChatGrupal(usuario);
        }
        if (opcion == 10)
        {
            SingletonUsuarios::obtenerInstancia().aniadirParticipanteChatGrupal(usuario);
        }
        if (opcion == 11)
        {
            SingletonUsuarios::obtenerInstancia().enviarMensajeChat(usuario);
        }
        if (opcion == 12)
        {
            SingletonUsuarios::obtenerInstancia().verMensajesDeCiertoChat(usuario);
        }
        if (opcion == 13)
        {
            SingletonUsuarios::obtenerInstancia().usarCamara(usuario);
        }
        if (opcion == 14)
        {
            seguir = false;
            usuario->setHoraUltimaVez(fecha.muestraHora());
            cout << "Saliendo de la cuenta" << endl;
            system("pause");
            system("cls");
        }
    }
    
}

void WhatsApp::entrarSalirCuentas()
{
    bool seguirEnWhats = true;
    string numTelefono;
    int opcion;
    while (seguirEnWhats)
    {
        
        Ayuda::menuCuentas();
        cin >> opcion;
        if (opcion == 1)
        {
            system("cls");
            cout << "Porfavor digame su numero de telefono para acceder a su cuenta" << endl;
            Validador::capturarPosibleExcepcionDeNumNoValido(numTelefono);
            Usuario* uEncontrado = SingletonUsuarios::obtenerInstancia().getModUsuarios()->buscar(new Usuario(numTelefono));
            if (uEncontrado != NULL)
            {
                cout << "Inicion de seion exitoso" << endl;
                system("pause");
                system("cls");
                hacerActividades(uEncontrado);
            }
            else
            {
                cout << "Este numero de telefono no esta registrado en whatsapp volviendo al inicio de sesion" << endl;
                
                system("pause");
                system("cls");
            }
        }
        if (opcion == 2)
        {
            system("cls");
            registrarUsuario();
        }
        if (opcion == 3)
        {
            cout << "Saliendo de WhatsApp" << endl;
            seguirEnWhats = false;
            system("pause");
            system("cls");
        }
        
    }
    
}



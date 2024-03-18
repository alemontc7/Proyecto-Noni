#include "SingletonUsuarios.h"

int SingletonUsuarios::idEstado;
int SingletonUsuarios::idLlamada;

int SingletonUsuarios::idMensaje;
SingletonUsuarios& SingletonUsuarios::obtenerInstancia()
{
    static SingletonUsuarios instancia;
    return instancia;
    idEstado = 0;
    idLlamada = 0;
    idMensaje = 0;
    
}

SingletonUsuarios::~SingletonUsuarios()
{
}

ModGen<Usuario>* SingletonUsuarios::getModUsuarios()
{
    return &usuarios;
}

void SingletonUsuarios::registrarContactoParaUsuario(Usuario* usuario)
{
    /*system("pause");
    system("cls");*/
    string numContactoAmigo;
    /*Usuario* uEncontrado = usuarios.buscar(usuario);*/
    /*if (uEncontrado != NULL)
    {*/

        cout << "Digame el numero de telefono del usuario al cual quiere aniadir a sus contactos" << endl;
       /* try
        {
            cin >> numContactoAmigo;
            if (Validador::validarSiUnaCadenaEsUnNum(numContactoAmigo) == false)
            {
                
                throw exception("Numero de telefono no valido");
            }
        }
        catch (exception& e)
        {
            cout<<e.what()<<endl;
            Ayuda::mensajeParaNumeroNoValido();
            Validador::obligarAlUsuarioPonerCadenaValidaDeNums(numContactoAmigo);
        }*/
        Validador::capturarPosibleExcepcionDeNumNoValido(numContactoAmigo);
        Usuario* uAmigoEncontrado = usuarios.buscar(new Usuario(numContactoAmigo));
        if (uAmigoEncontrado != NULL)
        {
            usuario->getModContactos()->registrar(uAmigoEncontrado);
            cout << "Se registro al contacto con exito" << endl;
        }
        else
        {
            cout << "El usuario al cual quiere aniadir a sus contactos no tiene whatsapp" << endl;
        }
   /* }
    else
    {
        cout << "Este usuario no tiene una cuenta de whatsapp" << endl;
    }*/
        //lo que esta comentado esta comentado porque la variable recibida en esta funcion
        //es un usuario que fija esta registrado ya que si inicio sesion significa que esta registrado en whats,
        //y si inicio sesion puede usar el registrar estado
}

void SingletonUsuarios::registrarEstadoParaUsuario(Usuario* usuario)
{
    //no vere si el usuario esta o no en el sistema, pues si o si lo esta ya que si inicio sesion y luego pudo acceder
    // a registrar estado al iniciarse sesion ya se verifico si estaba o no en el sistema de whatsapp
    FechaHora fh;
    int duracionEstado;
    string nombre;
    string contenidoEstadoEscrito;
    int opcion;
    
    cout << "Ingrese el tipo de estado que registrara" << endl;
    Ayuda::menuTiposDeEstado();
    cin >> opcion;
    system("pause");
    system("cls");
    if (opcion == 1)
    {
        cout << "Ingrese el nombre de la imagen que se buscara en su galeria para subirla a su estado" << endl;
        cin.ignore();
        getline(cin, nombre);
        nombre = nombre + ".jpg";
        cout << "Ingrese la duracion que quiere que tenga su estado en segundos\n";
        cin >> duracionEstado;
        Imagen* estadoDelTipoImagen = new Imagen(idEstado, fh.muestraFechaCompletaEnCadena(), duracionEstado, nombre);
        idEstado++;
        usuario->getModEstados()->registrar(estadoDelTipoImagen);
    }
    if (opcion == 2)
    {
        cout << "Ingrese el contenido que tendra su estado del tipo escrito" << endl;
        cin.ignore();
        getline(cin, contenidoEstadoEscrito);
        cout << "Ingrese la duracion que quiere que tenga su estado en segundos\n";
        cin >> duracionEstado;
        Escrito* estadoDelTipoEscrito = new Escrito(idEstado, fh.muestraFechaCompletaEnCadena(), duracionEstado, contenidoEstadoEscrito);
        idEstado++;
        usuario->getModEstados()->registrar(estadoDelTipoEscrito);
    }
}

void SingletonUsuarios::realizarLlamadaSimple(Usuario* usuario)
{
    string numContactoAmigo;
    cout << "Digame el numero de contacto al cual llamara" << endl;
    Validador::capturarPosibleExcepcionDeNumNoValido(numContactoAmigo);
    //no busco entre los contactos del usuario pues el usuario puede llamar a quien quiera
    Usuario* uEncontrado = usuarios.buscar(new Usuario(numContactoAmigo));
    if (uEncontrado != NULL)
    {
        LIndividual* llamada=new LIndividual(idLlamada," "," ",usuario,uEncontrado);
        usuario->getModLlamadas()->registrar(llamada);
        uEncontrado->getModLlamadas()->registrar(llamada); 
        int opcion;
        cout << "1-.Colgar la llamada" << endl;
        cout << "2-.Volver al menu de acciones de usuario" << endl;
        cin >> opcion;
        system("pause");
        system("cls");
        if (opcion == 1)
        {
            FechaHora fecha;
            llamada->setDuracion(0);
            llamada->setEstado("Cancelada");
            llamada->setInicio(fecha.muestraHora());
            llamada->setFin(fecha.muestraHora());
        }
        if (opcion == 2)
        {

        }

        
    }
    else
    {
        cout << "El usuario al cual intenta llamar no tiene whatsapp" << endl;
    }
}
void SingletonUsuarios::verLlamadaEntrante(Usuario* usuario)
{
    FechaHora fecha;
    int opcion;
    Llamada* llamada_A_Setear=NULL;
    for (int i = 0; i < usuario->getModLlamadas()->getInd(); i++)
    {
        llamada_A_Setear = usuario->getModLlamadas()->getPuntero(i);
        if (llamada_A_Setear->getEstado() == "Pendiente")
        {
            break;
        }
    }
    LIndividual* varia = (LIndividual*)llamada_A_Setear;
    if (*(varia->getReceptor()) == usuario)
    {
        if (llamada_A_Setear == NULL || llamada_A_Setear->getEstado() != "Pendiente")
        {
            cout << "Usted no tiene llamadas entrantes" << endl;
            system("pause");
            system("cls");
        }
        if (llamada_A_Setear != NULL && llamada_A_Setear->getEstado() == "Pendiente")
        {
            Ayuda::aceptarRechazarVolverAlMenu();
            cin >> opcion;
            if (opcion == 1)
            {
                int opcionTrasAceptarLlamada;
                string fechaInicioLlamada = fecha.muestraHora();
                cout << "Llamada contestada y en progreso" << endl;
                llamada_A_Setear->setEstado("Aceptada y en progreso");
                llamada_A_Setear->setInicio(fechaInicioLlamada);

                cout << "1-.Colgar la llamada" << endl;
                cout << "2-.Volver al menu de acciones de usuario" << endl;
                cin >> opcionTrasAceptarLlamada;
                system("pause");
                system("cls");
                if (opcionTrasAceptarLlamada == 1)
                {

                    llamada_A_Setear->setDuracion(10);
                    llamada_A_Setear->setEstado("Aceptada y finalizada");
                    llamada_A_Setear->setFin(fecha.muestraHora());
                }
                if (opcionTrasAceptarLlamada == 2)
                {

                }

            }
            if (opcion == 2)
            {
                llamada_A_Setear->setDuracion(0);
                llamada_A_Setear->setEstado("Rechazada");
                llamada_A_Setear->setInicio(fecha.muestraHora());
                llamada_A_Setear->setFin(fecha.muestraHora());
            }
            if (opcion == 3)
            {

            }
        }
    }
    else
    {
        cout << "Usted no tiene llamadas entrantes en este momento" << endl;
    }

}

void SingletonUsuarios::colgarLlamadaAunNoContestadaPorOtroUsuario(Usuario* usuario)
{

    FechaHora fecha;
    int opcion;
    Llamada* llamada_A_Setear = NULL;
    for (int i = 0; i < usuario->getModLlamadas()->getInd(); i++)
    {
        llamada_A_Setear = usuario->getModLlamadas()->getPuntero(i);
        if (llamada_A_Setear->getEstado() == "Pendiente")
        {
            break;
        }
    }
    LIndividual* varia = (LIndividual*)llamada_A_Setear;
    if (*(varia->getSolicitador())==usuario)
    {
        if (llamada_A_Setear == NULL || llamada_A_Setear->getEstado() != "Pendiente")
        {
            cout << "Usted no tiene llamadas aun no contestadas en progreso" << endl;
            system("pause");
            system("cls");
        }
        if (llamada_A_Setear != NULL && llamada_A_Setear->getEstado() == "Pendiente")
        {
            cout << "Elija una opcion" << endl;
            cout << "1-. Colgar la llamada" << endl;
            cout << "2-. Volver al menu de acciones de usuario" << endl;
            cin >> opcion;
            if (opcion == 1)
            {
                llamada_A_Setear->setDuracion(0);
                llamada_A_Setear->setEstado("Cancelada");
                llamada_A_Setear->setInicio(fecha.muestraHora());
                llamada_A_Setear->setFin(fecha.muestraHora());

            }
            if (opcion == 2)
            {

            }
        }

    }
    else
    {
        cout << "Usted no tiene llamadas realizadas en espera de ser contestadas" << endl;
    }
    
}

void SingletonUsuarios::volver_A_LlamadaContestada(Usuario* usuario)
{
    FechaHora fecha;
    int opcion;
    Llamada* llamada_A_Setear = NULL;
    for (int i = 0; i < usuario->getModLlamadas()->getInd(); i++)
    {
        llamada_A_Setear = usuario->getModLlamadas()->getPuntero(i);
        if (llamada_A_Setear->getEstado() == "Aceptada y en progreso")
        {
            break;
        }
    }
    if (llamada_A_Setear == NULL || llamada_A_Setear->getEstado() != "Aceptada y en progreso")
    {
        cout << "Usted no tiene llamadas contestadas en progreso" << endl;
        system("pause");
        system("cls");
    }
    if (llamada_A_Setear != NULL && llamada_A_Setear->getEstado() == "Aceptada y en progreso")
    {
        cout << "Elija una opcion" << endl;
        cout << "1-. Colgar la llamada" << endl;
        cout << "2-. Volver al menu de acciones de usuario" << endl;
        cin >> opcion;
        if (opcion == 1)
        {
            llamada_A_Setear->setFin(fecha.muestraHora());
            llamada_A_Setear->setDuracion(10);
            llamada_A_Setear->setEstado("Aceptada y finalizada");
        }
        if (opcion == 2)
        {

        }
    }
}

void SingletonUsuarios::verPerfilDeUnUsuario(Usuario* usuario)
{
    string fono;
    /*cout << "Ingrese el numero del perfil de usuario al cual quiere ver" << endl;
    cin.ignore();
    getline(cin, fono);*/
    cout << "Ingrese el numero del perfil de usuario al cual quiere ver" << endl;
    Validador::capturarPosibleExcepcionDeNumNoValido(fono);
    Usuario* uEncontrado = SingletonUsuarios::obtenerInstancia().getModUsuarios()->buscar(new Usuario(fono));
    if (uEncontrado != NULL)
    {
        cout << "Hora de ultima vez:" << endl;
        if (uEncontrado->getAjuste()->getPrivacidad()->getHoraUltimaVez() == "Todos")
        {
            cout << uEncontrado->getHoraUltimaVez()<<endl;
        }
        if (uEncontrado->getAjuste()->getPrivacidad()->getHoraUltimaVez() == "Mis contactos")
        {
            if(uEncontrado->getModContactos()->buscar(usuario)!=NULL)
            {
                cout << uEncontrado->getHoraUltimaVez()<<endl;
            }
            else
            {
                cout << "Este usuario configuro que la visualizacion de su ultima conexion solo la veran sus contactos y usted no esta entre ellos" << endl;
            }
        }
        if (uEncontrado->getAjuste()->getPrivacidad()->getHoraUltimaVez() == "Nadie")
        {
            cout << "Nadie puede ver la hora de ultima vez de este usuario" << endl;
        }



        cout << "Foto de perfil:" << endl;
        if (uEncontrado->getAjuste()->getPrivacidad()->getVisualizacionDeFoto() == "Todos")
        {
            cout << uEncontrado->getFotoDePerfil()<<endl;
        }
        if (uEncontrado->getAjuste()->getPrivacidad()->getVisualizacionDeFoto() == "Mis contactos")
        {
            if (uEncontrado->getModContactos()->buscar(usuario) != NULL)
            {
                cout << uEncontrado->getFotoDePerfil() << endl;
            }
            else
            {
                cout << "Este usuario configuro que la visualizacion de su foto de perfil solo la veran sus contactos y usted no esta entre ellos" << endl;
            }
        }
        if (uEncontrado->getAjuste()->getPrivacidad()->getVisualizacionDeFoto() == "Nadie")
        {
            cout << "Nadie puede ver la foto de perfil de este usuario" << endl;
        }





        cout << "Informacion de usuario:" << endl;
        if (uEncontrado->getAjuste()->getPrivacidad()->getVisualizacionInfo() == "Todos")
        {
            cout << uEncontrado->getInfo() << endl;
        }
        if (uEncontrado->getAjuste()->getPrivacidad()->getVisualizacionInfo() == "Mis contactos")
        {
            if (uEncontrado->getModContactos()->buscar(usuario) != NULL)
            {
                cout << uEncontrado->getInfo() << endl;
            }
            else
            {
                cout << "Este usuario no permite que usuarios que no estan en sus contactos puedan ver su informacion" << endl;
            }
        }
        if (uEncontrado->getAjuste()->getPrivacidad()->getVisualizacionInfo() == "Nadie")
        {
            cout << "Nadie puede ver la informacion de este usuario" << endl;
        }
        system("pause");
        system("cls");
    }
    else
    {
        cout << "El usuario del cual quiere ver el perfil no tiene whatsapp" << endl;
    }
}

void SingletonUsuarios::crearChatIndividualConUnUsuario(Usuario* usuario)
{
    string fono;
    cout << "Ingrese el numero de usuario con el cual iniciara un chat individual" << endl;
    Validador::capturarPosibleExcepcionDeNumNoValido(fono);
    Usuario* uEncontrado = usuarios.buscar(new Usuario(fono));
    if (uEncontrado != NULL)
    {
        cout << "Digame el nombre que le pondra al chat" << endl;
        string nombre;
        cin.ignore();
        getline(cin, nombre);
        Individual* indi = new Individual(nombre, uEncontrado, usuario);
        usuario->getModChats()->registrar(indi);
        uEncontrado->getModChats()->registrar(indi);
    }
    else
    {
        cout << "El usuario con el cual quiere inciar el chat no tiene whatsapp" << endl;
    }
    system("pause");
    system("cls");
}

void SingletonUsuarios::crearChatGrupal(Usuario* usuario)
{
    cout << "Ingrese el nombre del grupo" << endl;
    string nombre;
    cin.ignore();
    getline(cin, nombre);
    Grupal* grupal = new Grupal(nombre);
    usuario->getModChats()->registrar(grupal);
    grupal->getParticipantes()->registrar(usuario);
    cout << "Se creo el chat grupal con exito" << endl;
    system("pause");
    system("cls");
}

void SingletonUsuarios::aniadirParticipanteChatGrupal(Usuario* usuario)
{
    cout << "Ingrese el nombre del chat al cual incorporara integrantes" << endl;
    string nombre;
    cin.ignore();
    getline(cin, nombre);
    Chat* chatGrupalEncontrado = usuario->getModChats()->buscar(new Chat(nombre));
    if (chatGrupalEncontrado != NULL)
    {
        string fono;
        cout << "Ingrese el numero de telefono del usuario el cual se desea agregar al chat grupal" << endl;
        Validador::capturarPosibleExcepcionDeNumNoValido(fono);
        Usuario* uIntegrado = usuarios.buscar(new Usuario(fono));
        if (uIntegrado != NULL)
        {
            uIntegrado->getModChats()->registrar(chatGrupalEncontrado);
            Grupal* varia = (Grupal*)chatGrupalEncontrado;
            varia->getParticipantes()->registrar(uIntegrado);
            cout << "Se registro al usuario con exito" << endl;
        }
        else
        {
            cout << "El usuario al cual trato de ingresar al grupo no tiene whatsapp" << endl;
        }
    }
    else
    {
        cout << "El chat grupal que me indicio no existe" << endl;
    }
    system("pause");
    system("cls");
}

void SingletonUsuarios::enviarMensajeChat(Usuario* usuario)
{
    string nombreChat;
    cout << "Ingrese el nombre del chat al cual enviara el mensaje" << endl;
    cin.ignore();
    getline(cin, nombreChat);
    Chat* chatEncontrado = usuario->getModChats()->buscar(new Chat(nombreChat));
    if (chatEncontrado != NULL)
    {
        int opcionTipoMensaje;
        cout << "Seleccione el tipo de menaje que enviara" << endl;
        Ayuda::menuTiposDeMensaje();
        cin >> opcionTipoMensaje;
        if (opcionTipoMensaje == 1)
        {
            cout << "Escriba su mensaje textual" << endl;
            string mensaje;
            cin.ignore();
            getline(cin, mensaje);
            //Mensaje* mRegistrado = new Textual(idMensaje, "Entregado", mensaje);
            chatEncontrado->getModMensajes()->registrar(new Textual(idMensaje, "Entregado", mensaje));
            idMensaje++;
            cout << "Se envio el mensaje con exito" << endl;
            system("pause");
            system("cls");
        }
        if (opcionTipoMensaje == 2)
        {
            cout << "Escriba el nombre de su archivo" << endl;
            string nombreArch;
            cin.ignore();
            getline(cin, nombreArch);
            cout << "Escriba la extension de su archivo" << endl;
            string extensionArch;
            //cin.ignore();
            getline(cin, extensionArch);
            //Mensaje* mRegistrado = new Textual(idMensaje, "Entregado", mensaje);
            chatEncontrado->getModMensajes()->registrar(new Archivo(idMensaje,"Entregado",nombreArch,extensionArch));
            idMensaje++;
            cout << "Se envio el mensaje con exito" << endl;
            system("pause");
            system("cls");
        }
        if (opcionTipoMensaje == 3)
        {
            string fono;
            cout << "Escriba el celular del contacto el cual enviara como mensaje" << endl;
            Validador::capturarPosibleExcepcionDeNumNoValido(fono);
            Usuario* uEncontrado = usuario->getModContactos()->buscar(new Usuario(fono));
            if (uEncontrado != NULL)
            {
                string info=uEncontrado->getInfoDeContactoParaEnviar();
                
                //Mensaje* mRegistrado = new Textual(idMensaje, "Entregado", mensaje);
                chatEncontrado->getModMensajes()->registrar(new InfContacto(idMensaje,"Entregado",info));
                idMensaje++;
                cout << "Se envio el mensaje con exito" << endl;
            }
            else
            {
                cout << "Este usuario no esta entre sus contactos" << endl;
            }
            system("pause");
            system("cls");

        }
        if (opcionTipoMensaje == 4)
        {
            int x;
            int y;
            cout << "Digame las coordenadas x en las que esta " << endl;
            cin >> x;
            cout<< "Digame las coordenadas y en las que esta " << endl;
            cin >> y;
            chatEncontrado->getModMensajes()->registrar(new Locacion(idMensaje, "Entregado", x, y));
            idMensaje++;
            cout << "Se envio el mensaje con exito" << endl;
            system("pause");
            system("cls");
        }
        if (opcionTipoMensaje == 5)
        {
            
            int cantidadOpciones;
            string opcion;
            string pregunta;
            cout << "Ingrese la pregunta de su encuesta" << endl;
            cin.ignore();
            getline(cin, pregunta);
            Encuesta* encuesta = new Encuesta(idMensaje,pregunta);
            cout << "Porfavor indiqueme cuantas opciones tendra su encuesta" << endl;
            cin >> cantidadOpciones;
            for (int i = 0; i < cantidadOpciones; i++)
            {
                cout << "Escriba la opcion " << i + 1 << endl;
                cin >> opcion;
                encuesta->agregarPregunta(opcion);
                cout << "Se agrego la opcion de forma exitosa" << endl;
            }
            chatEncontrado->getModMensajes()->registrar(encuesta);
            idMensaje++;
            cout << "Se envio el menaje de forma exitosa" << endl;
            system("pause");
            system("cls");
        }

       
    }
    else
    {
        cout << "El chat grupal que me indicio no existe" << endl;
    }
    system("pause");
    system("cls");

}

void SingletonUsuarios::verMensajesDeCiertoChat(Usuario* usuario)
{
    string nombreChat;
    cout << "Ingrese el nombre del chat del cual quiere ver los mensajes" << endl;
    cin.ignore();
    getline(cin, nombreChat);
    Chat* chatEncontrado = usuario->getModChats()->buscar(new Chat(nombreChat));
    if (chatEncontrado != NULL)
    {
        cout << chatEncontrado->getModMensajes()->toJson(Mensaje::mensajeToJson) << endl;
    }
    else
    {
        cout << "El chat grupal que me indicio no existe" << endl;
    }
    system("pause");
    system("cls");
}

void SingletonUsuarios::usarCamara(Usuario* usuario)
{
    cout << "La camara tomo una foto " << endl;
    system("pause");
    system("cls");
}


SingletonUsuarios::SingletonUsuarios():usuarios(1000)
{
   
}

#include "Usuario.h"
#include "FechaHora.h"
FechaHora fecha;

Usuario::Usuario(string fono, string nombre, string info, Ajuste* ajuste, Camara* camara, string foto) :chats(100), llamadas(100),contactos(100),estados(100)
{
    this->fono = fono;
    this->nombre = nombre;
    this->info = info;
    this->ajuste = ajuste;
    
    this->camara = camara;
    this->foto = foto;
    this->horaUltimaVez = "Aun no realizo la primera desconexion de su cuenta";
}



Usuario::Usuario(string fono) :chats(1000), llamadas(100),contactos(100),estados(100)
{
    this->fono = fono;
}

Usuario::~Usuario()
{
}

string Usuario::toJson()
{
    stringstream ss;
    ss << "{";
    ss << "\"Celular\":" << "\"" << fono << "\"" << ",";
    ss << "\"Nombre\":" << "\"" << nombre << "\"" << ",";
    ss << "\"Informacion del usuario\":" << "\"" << info << "\"" << ",";
    ss << "\"Foto de perfil\":" << "\"" << foto << "\"" << ",";
    ss << "\"Ultima vez conectado\":" << "\""<<horaUltimaVez << "\"" << ",";
    ss << "\"Ajuste\":" << ajuste->toJson() << ",";
    ss << "\"Camara\":" << camara->toJson() <<",";
    ss << "\"Contactos\":" << contactos.toJson(Usuario::usuarioToJsonSoloNum)<<",";
    ss << "\"Chats\":" << chats.toJson(Chat::chatToJson) << ",";
    ss << "\"Llamadas\":" << llamadas.toJson(Llamada::llamadaToJson) << ",";
    ss << "\"Estados\":" << estados.toJson(Estado::estadoToJson);
    ss << "}";
    return ss.str();
}

string Usuario::toJsonSoloNum()
{
    stringstream ss;
    ss << "\"" << fono << "\"";
    return ss.str();
}

string Usuario::usuarioToJson(Usuario* usuario)
{
    return usuario->toJson();
}

string Usuario::usuarioToJsonSoloNum(Usuario* usuario)
{
    return usuario->toJsonSoloNum();
}

ModGen<Chat>* Usuario::getModChats()
{
    return &chats;
}

ModGen<Llamada>* Usuario::getModLlamadas()
{
    return &llamadas;
}

ModGen<Usuario>* Usuario::getModContactos()
{
    return &contactos;
}

ModGen<Estado>* Usuario::getModEstados()
{
    return &estados;
}

bool Usuario::operator==(Usuario* u)
{
    return fono==u->fono;
}

string Usuario::getNombre()
{
    return nombre;
}

void Usuario::setHoraUltimaVez(string horaUltimaVez)
{
    this->horaUltimaVez = horaUltimaVez;
}

Ajuste* Usuario::getAjuste()
{
    return ajuste;
}

string Usuario::getHoraUltimaVez()
{
    return horaUltimaVez;
}

string Usuario::getFotoDePerfil()
{
    return foto;
}

string Usuario::getInfo()
{
    return info;
}

string Usuario::getInfoDeContactoParaEnviar()
{
    return "Telefono del contacto: "+fono+"-----Nombre del contacto: " + nombre;
}





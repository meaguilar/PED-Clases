#include <iostream>
#include <map>
#include <iterator>
#include <string>

struct Tiobe
{
    std::string lenguaje_programacion;
    float puntaje;
};

void SolicitarDatos(Tiobe &inf_tiobe);
void Imprimir(const std::map<std::string, Tiobe> &map);
void Buscar(const std::map<std::string, Tiobe> &map, std::string nombre);
void Borrar(std::map<std::string, Tiobe> &map, std::string nombre);

int main()
{
    std::map<std::string, Tiobe> map;
    Tiobe inf_tiobe;
    char continuar;
    std::string lenguaje_buscar;

    do
    {
        SolicitarDatos(inf_tiobe);

        map.insert({inf_tiobe.lenguaje_programacion, inf_tiobe});
        // map.emplace(inf_tiobe.lenguaje_programacion, inf_tiobe);

        std::cout << "Deseas agregar otro lenguaje (s/n): ";
        std::cin >> continuar;

    } while (continuar == 's');

    // Imprimir datos
    std::cout << "\nLenguajes registrados:\n";
    Imprimir(map);

    // Buscar un lenguaje
    std::cout << "\nIngresa el lenguaje que deseas buscar: ";
    std::cin >> lenguaje_buscar;

    Buscar(map, lenguaje_buscar);

    // Borrar un lenguaje
    std::cout << "\nIngresa el lenguaje que deseas borrar: ";
    std::cin >> lenguaje_buscar;

    Borrar(map, lenguaje_buscar);

    // Imprimir despues de borrar
    std::cout << "\nLenguajes despues de borrar:\n";
    Imprimir(map);

    return 0;
}

void SolicitarDatos(Tiobe &inf_tiobe)
{
    std::cout << "Ingresar el nombre del lenguaje: ";
    std::cin >> inf_tiobe.lenguaje_programacion;

    std::cout << "Ingresar el puntaje obtenido: ";
    std::cin >> inf_tiobe.puntaje;
}

// Imprimir utilizando iterator
void Imprimir(const std::map<std::string, Tiobe> &map)
{
    std::map<std::string, Tiobe>::const_iterator it;

    for (it = map.begin(); it != map.end(); it++)
    {
        std::cout << "Lenguaje: " << it->first
                  << " Puntaje: " << it->second.puntaje << "\n";
    }
}

void Buscar(const std::map<std::string, Tiobe> &map, std::string nombre)
{
    // iterator, permite acceder y solamente leer elementos
    std::map<std::string, Tiobe>::const_iterator it;

    it = map.find(nombre);

    if (it != map.end())
    {
        std::cout << "Lenguaje encontrado: " << it->first
                  << " Puntaje: " << it->second.puntaje << "\n";
    }
    else
    {
        std::cout << "Lenguaje no encontrado\n";
    }
}

void Borrar(std::map<std::string, Tiobe> &map, std::string nombre)
{
    // iterator, permite acceder y modificar elementos
    std::map<std::string, Tiobe>::iterator it;

    it = map.find(nombre);

    if (it != map.end())
    {
        map.erase(it);
        std::cout << "Lenguaje eliminado correctamente\n";
    }
    else
    {
        std::cout << "Lenguaje no encontrado\n";
    }
}

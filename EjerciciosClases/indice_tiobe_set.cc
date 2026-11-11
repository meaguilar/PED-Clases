#include <iostream>
#include <iterator>
#include <set>
#include <string>


struct Tiobe
{
    std::string lenguaje_programacion;
    float puntaje;

    // Criterio de comparación por nombre
    bool operator<(const Tiobe &tiobe) const {
        return lenguaje_programacion < tiobe.lenguaje_programacion;
    }
};

void SolicitarDatos(Tiobe &inf_tiobe);
void Imprimir(const std::set<Tiobe> &set);
void Buscar(const std::set<Tiobe> &set, std::string lenguaje_borrar);
void Borrar(std::set<Tiobe> &set, std::string lenguaje_borrar);

int main()
{
    std::set<Tiobe> set;
    Tiobe inf_tiobe;
    char continuar;
    std::string lenguaje_buscar;

    // Ingresar datos
    do
    {
        SolicitarDatos(inf_tiobe);
        set.insert(inf_tiobe);

        std::cout << "Deseas agregar otro lenguaje (s/n): ";
        std::cin >> continuar;

    } while (continuar == 's');

    // Imprimir datos
    std::cout << "\nLenguajes registrados:\n";
    Imprimir(set);

    // Buscar un lenguaje
    std::cout << "\nIngresa el nombre que deseas buscar: ";
    std::cin >> lenguaje_buscar;

    Buscar(set, lenguaje_buscar);

    // Borrar un lenguaje
    std::cout << "\nIngresa el nombre que deseas borrar: ";
    std::cin >> lenguaje_buscar;

    Borrar(set, lenguaje_buscar);

    // Imprimir despues de borrar
    std::cout << "\nLenguajes despues de borrar:\n";
    Imprimir(set);

    return 0;
}

// Solicitar datos
void SolicitarDatos(Tiobe &inf_tiobe)
{
    std::cout << "Ingresar el nombre del lenguaje: ";
    std::cin >> inf_tiobe.lenguaje_programacion;

    std::cout << "Ingresar el puntaje obtenido: ";
    std::cin >> inf_tiobe.puntaje;
}

// Imprimir datos
void Imprimir(const std::set<Tiobe> &set)
{
    for (auto valor : set)
    {
        std::cout << "Lenguaje: " << valor.lenguaje_programacion
                  << " - Puntaje: " << valor.puntaje << "\n";
    }
}


void Buscar(const std::set<Tiobe> &set, std::string lenguaje_borrar)
{
    Tiobe buscar;
    buscar.lenguaje_programacion = lenguaje_borrar;

    std::set<Tiobe>::const_iterator it;

    it = set.find(buscar);

    if (it != set.end())
    {
        std::cout << "Lenguaje encontrado: "
                  << it->lenguaje_programacion
                  << " - Puntaje: " << it->puntaje << "\n";
    }
    else
    {
        std::cout << "Lenguaje no encontrado\n";
    }
}

void Borrar(std::set<Tiobe> &set, std::string lenguaje_borrar)
{
    Tiobe borrar;
    borrar.lenguaje_programacion = lenguaje_borrar;

    if (set.erase(borrar) > 0)
        std::cout << "Lenguaje eliminado correctamente\n";
    else
        std::cout << "Lenguaje no encontrado\n";
}

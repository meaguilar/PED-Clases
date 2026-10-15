#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

struct Luchador
{
    std::string nombre;
    float peso;
};

void SolicitarDatos(Luchador &l);
void Imprimir(std::list<Luchador> lista);
bool CompararPesos(const Luchador &a, const Luchador &b);
void BuscarLuchadorPorNombre(std::list<Luchador> lista, std::string nombre_buscar);

int main()
{
    char continuar;
    std::string nombre_luchador_buscar;
    struct Luchador luchador;
    std::list<Luchador> lista_luchadores;

    do
    {
        SolicitarDatos(luchador);
        lista_luchadores.push_front(luchador);

        std::cout << "Deseas agregar otro luchador (s/n): ";
        std::cin >> continuar;

    } while (continuar == 's');

    lista_luchadores.sort(CompararPesos);

    Imprimir(lista_luchadores);

    std::cout << "\n Ingresa el nombre del luchador a buscar: ";
    std::cin >> nombre_luchador_buscar;

    BuscarLuchadorPorNombre(lista_luchadores, nombre_luchador_buscar);

    return 0;
}

void SolicitarDatos(Luchador &l)
{
    std::cout << "Ingresar el nombre del luchador: ";
    std::cin >> l.nombre;

    std::cout << "Ingresar el peso en libras: ";
    std::cin >> l.peso;
}

void Imprimir(std::list<Luchador> lista)
{

    std::cout << "\nImprimiendo la lista de luchadores registrados....\n";

    while (!lista.empty())
    {
        std::cout << "Nombre del luchador: "
                  << lista.front().nombre << " - peso: "
                  << lista.front().peso << " Lbs.\n";
        lista.pop_front();
    }
}

bool CompararPesos(const Luchador &a, const Luchador &b)
{
    return a.peso < b.peso;
}

void BuscarLuchadorPorNombre(std::list<Luchador> lista, std::string nombre_buscar)
{
    std::list<Luchador>::iterator resultado_it;

    resultado_it = lista.begin();

    while (resultado_it != lista.end())
    {
        resultado_it = std::find_if(resultado_it, lista.end(),
                                    [&nombre_buscar](const Luchador &luchador)
                                    {
                                        return luchador.nombre == nombre_buscar;
                                    });

        if (resultado_it != lista.end())
        {
            std::cout << "Nombre del luchador "
                      << resultado_it->nombre
                      << " - " << resultado_it->peso << " Lbs. \n";
        }

        resultado_it++;
    }
}


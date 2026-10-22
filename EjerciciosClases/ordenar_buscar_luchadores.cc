#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <chrono>

struct Luchador
{
    std::string nombre;
    float peso;
};

void SolicitarDatos(Luchador &l);
void Imprimir(std::list<Luchador> lista);
bool CompararPesos(const Luchador &a, const Luchador &b);
bool CompararNombres(const Luchador &a, const Luchador &b);
void BuscarLuchadorPorNombre(std::list<Luchador> lista, std::string nombre_buscar);
void VerificarExistenciaLuchador(std::list<Luchador> lista, std::string nombre_buscar);

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

    lista_luchadores.sort(CompararNombres);

    Imprimir(lista_luchadores);

    std::cout << "\n Ingresa el nombre del luchador a buscar: ";
    std::cin >> nombre_luchador_buscar;

    // Medir tiempo de busqueda lineal
    auto inicio_tiempo_busqueda_lineal = std::chrono::high_resolution_clock::now();

    BuscarLuchadorPorNombre(lista_luchadores, nombre_luchador_buscar);

    auto fin_tiempo_busqueda_lineal = std::chrono::high_resolution_clock::now();

    auto duracion_total_busqueda_lineal =
        std::chrono::duration_cast<std::chrono::microseconds>(
            fin_tiempo_busqueda_lineal - inicio_tiempo_busqueda_lineal)
            .count();

    std::cout << "Tiempo de busqueda lineal: "
              << duracion_total_busqueda_lineal << " microsegundos\n";

    // Medir tiempo de busqueda binaria
    auto inicio_tiempo_busqueda_binaria = std::chrono::high_resolution_clock::now();
    VerificarExistenciaLuchador(lista_luchadores, nombre_luchador_buscar);

    auto fin_tiempo_busqueda_binaria = std::chrono::high_resolution_clock::now();

    auto duracion_total_busqueda_binaria =
        std::chrono::duration_cast<std::chrono::microseconds>(
            fin_tiempo_busqueda_binaria - inicio_tiempo_busqueda_binaria)
            .count();

    std::cout << "Tiempo de busqueda binaria: "
              << duracion_total_busqueda_binaria << " microsegundos\n";

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
bool CompararNombres(const Luchador &a, const Luchador &b)
{
    return a.nombre < b.nombre;
}

// Implementación de algoritmo de busqueda lineal
void BuscarLuchadorPorNombre(std::list<Luchador> lista, std::string nombre_buscar)
{
    std::list<Luchador>::iterator resultado_it;
    bool encontrado = true;

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

            resultado_it++;
        }
        else
        {
            encontrado = false;
        }
    }
    if (!encontrado)
    {
        std::cout << "Busqueda finalizada.\n";
    }
}

// Implementación de algoritmo de busqueda binaria
void VerificarExistenciaLuchador(std::list<Luchador> lista, std::string nombre_buscar)
{
    Luchador luchador;
    luchador.nombre = nombre_buscar;

    bool existe = std::binary_search(lista.begin(), lista.end(), luchador,
                                     [](const Luchador &a, const Luchador &b)
                                     {
                                         return a.nombre < b.nombre;
                                     });

    (existe) ? std::cout << "El luchador " << nombre_buscar
                         << " existe en la lista.\n"
             : std::cout << "El luchador " << nombre_buscar
                         << " no existe en la lista.\n";
}
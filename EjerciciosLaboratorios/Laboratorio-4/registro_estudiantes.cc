#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

struct Estudiante
{
    std::string nombre;
    int edad;
};

void SolicitarDatos(Estudiante &estudiante);
void Imprimir(std::list<Estudiante> lista);
bool CompararEdades(const Estudiante &a, const Estudiante &b);
void BuscarEstudiantePorNombre(std::list<Estudiante> lista, std::string nombre_buscar);
void BuscarEstudiantePorEdadBinaria(std::list<Estudiante> lista, int edad_buscar);

int main()
{
    int opcion;
    std::string nombre_estudiante_buscar;
    int edad_estudiante_buscar;
    struct Estudiante estudiante;
    std::list<Estudiante> lista_estudiantes;

    do
    {
        std::cout << "\n=== Registro de Estudiantes ===\n";
        std::cout << "1. Agregar estudiante\n";
        std::cout << "2. Ordenar y mostrar estudiantes\n";
        std::cout << "3. Buscar estudiante por nombre (Lineal - find_if)\n";
        std::cout << "4. Verificar edad de estudiante (Binaria - binary_search)\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            SolicitarDatos(estudiante);
            lista_estudiantes.push_front(estudiante);
            std::cout << "Estudiante registrado correctamente.\n";
            break;

        case 2:
            if (lista_estudiantes.empty())
            {
                std::cout << "La lista esta vacia. Agregue estudiantes primero.\n";
            }
            else
            {
                lista_estudiantes.sort(CompararEdades);
                Imprimir(lista_estudiantes);
            }
            break;

        case 3:
            if (lista_estudiantes.empty())
            {
                std::cout << "La lista esta vacia. No se puede realizar la busqueda.\n";
            }
            else
            {
                std::cout << "Ingresa el nombre del estudiante a buscar: ";
                std::cin >> nombre_estudiante_buscar;
                BuscarEstudiantePorNombre(lista_estudiantes, nombre_estudiante_buscar);
            }
            break;

        case 4:
            if (lista_estudiantes.empty())
            {
                std::cout << "La lista esta vacia. No se puede realizar la busqueda.\n";
            }
            else
            {
                // Se asegura que la lista este ordenada por edad antes de la busqueda binaria
                lista_estudiantes.sort(CompararEdades);
                std::cout << "Ingresa la edad a verificar con busqueda binaria: ";
                std::cin >> edad_estudiante_buscar;
                BuscarEstudiantePorEdadBinaria(lista_estudiantes, edad_estudiante_buscar);
            }
            break;

        case 0:
            std::cout << "Saliendo del programa...\n";
            break;

        default:
            std::cout << "Opcion no valida. Intente de nuevo.\n";
            break;
        }

    } while (opcion != 0);

    return 0;
}

void SolicitarDatos(Estudiante &estudiante)
{
    std::cout << "Ingresar el nombre del estudiante: ";
    std::cin >> estudiante.nombre;

    std::cout << "Ingresar la edad en anios: ";
    std::cin >> estudiante.edad;
}

void Imprimir(std::list<Estudiante> lista)
{
    std::cout << "\nImprimiendo la lista de estudiantes registrados (ordenados por edad)...\n";

    while (!lista.empty())
    {
        std::cout << "Nombre del estudiante: "
                  << lista.front().nombre << " - edad: "
                  << lista.front().edad << " anios.\n";
        lista.pop_front();
    }
}

bool CompararEdades(const Estudiante &a, const Estudiante &b)
{
    return a.edad < b.edad;
}

void BuscarEstudiantePorNombre(std::list<Estudiante> lista, std::string nombre_buscar)
{
    std::list<Estudiante>::iterator resultado_it = lista.begin();
    bool encontrado = false;

    while (resultado_it != lista.end())
    {
        resultado_it = std::find_if(resultado_it, lista.end(),
                                    [&nombre_buscar](const Estudiante &estudiante)
                                    {
                                        return estudiante.nombre == nombre_buscar;
                                    });

        if (resultado_it != lista.end())
        {
            std::cout << "Estudiante encontrado: "
                      << resultado_it->nombre
                      << " - " << resultado_it->edad << " anios.\n";
            encontrado = true;
            resultado_it++;
        }
    }

    if (!encontrado)
    {
        std::cout << "No se encontro ningun estudiante con el nombre \"" << nombre_buscar << "\".\n";
    }
}

void BuscarEstudiantePorEdadBinaria(std::list<Estudiante> lista, int edad_buscar)
{
    Estudiante clave;
    clave.edad = edad_buscar;

    bool existe = std::binary_search(lista.begin(), lista.end(), clave,
                                     [](const Estudiante &a, const Estudiante &b)
                                     {
                                         return a.edad < b.edad;
                                     });

    if (existe)
    {
        std::cout << "Confirmado (Busqueda Binaria): Si hay estudiantes con " << edad_buscar << " anios.\n";
    }
    else
    {
        std::cout << "Resultado (Busqueda Binaria): No hay estudiantes con " << edad_buscar << " anios.\n";
    }
}
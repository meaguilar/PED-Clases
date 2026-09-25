#include <iostream>
#include <string>

// Struct para almacenar los datos de una canción
struct Cancion
{
    std::string titulo;
    std::string artista;
    float duracion; // en minutos
    std::string genero;
};

// Struct Nodo - Representa cada nodo de la lista

struct Nodo
{
    Cancion cancion; // Dato almacenado en el nodo
    Nodo *siguiente; // Puntero al siguiente nodo
    Nodo *anterior;  // Puntero al nodo anterior
};

// Variables globales

Nodo *inicio = nullptr; // Puntero al primer nodo
Nodo *fin = nullptr;    // Puntero al último nodo

// Declaraciones de funciones
Cancion pedirDatosCancion();
void agregarCancion(Cancion cancion);
void mostrarPlaylist();
void mostrarPlaylistInversa();
void buscarCancion(Cancion cancion);
void eliminarCancion(Cancion cancion);
void contarCanciones();
void calcularDuracionTotal();
void liberarMemoria();
std::string clasificarDuracion(float duracion);

int main()
{
    int opcion;

    do
    {
        std::cout << "\n=== Biblioteca de Canciones ===\n";
        std::cout << "1. Agregar cancion\n";
        std::cout << "2. Mostrar playlist (inicio -> fin)\n";
        std::cout << "3. Mostrar playlist (fin -> inicio)\n";
        std::cout << "4. Buscar cancion\n";
        std::cout << "5. Eliminar cancion\n";
        std::cout << "6. Duracion total de playlist\n";
        std::cout << "0. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        std::cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion)
        {
        case 1:
        {
            Cancion nueva = pedirDatosCancion();
            agregarCancion(nueva);
        }
        break;
        case 2:
            mostrarPlaylist();
            break;
        case 3:
            mostrarPlaylistInversa();
            break;
        case 4:
        {
            Cancion buscada;

            std::cout << "\n--- Buscar cancion ---\n";
            std::cout << "Ingrese el titulo de la cancion: ";
            std::getline(std::cin, buscada.titulo);

            buscarCancion(buscada);
            break;
        }
        case 5:
        {
            Cancion eliminada;

            std::cout << "\n--- Eliminar cancion ---\n";
            std::cout << "Ingrese el titulo de la cancion a eliminar: ";
            std::getline(std::cin, eliminada.titulo);

            eliminarCancion(eliminada);
            break;
        }
        case 6:
            calcularDuracionTotal();
            break;
        case 0:
            std::cout << "Saliendo del programa...\n";
            liberarMemoria();
            break;
        default:
            std::cout << "Opcion invalida. Intente nuevamente.\n";
        }
    } while (opcion != 0);

    return 0;
}

// Pedir los datos de una canción
Cancion pedirDatosCancion()
{
    Cancion nueva;

    std::cout << "\n--- Agregar nueva cancion ---\n";
    std::cout << "Titulo: ";
    std::getline(std::cin, nueva.titulo);
    std::cout << "Artista: ";
    std::getline(std::cin, nueva.artista);
    std::cout << "Duracion (minutos): ";
    while (!(std::cin >> nueva.duracion) || nueva.duracion < 0)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        if (nueva.duracion < 0)
        {
            std::cout << "No se aceptan numeros negativos. Intente nuevamente: ";
        }
        else
        {
            std::cout << "Solo se aceptan numeros. Intente nuevamente: ";
        }
    }
    std::cin.ignore();
    std::cout << "Genero: ";
    std::getline(std::cin, nueva.genero);
    return nueva;
}

// Agregar una canción al final de la lista

void agregarCancion(Cancion cancion)
{
    // Crear el nuevo nodo
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->cancion = cancion;
    nuevo_nodo->siguiente = nullptr;
    nuevo_nodo->anterior = nullptr;

    // Insertar en la lista
    if (inicio == nullptr)
    {
        // Lista vacía - primer elemento
        inicio = nuevo_nodo;
        fin = nuevo_nodo;
    }
    else
    {
        // Insertar al final
        nuevo_nodo->anterior = fin;
        fin->siguiente = nuevo_nodo;
        fin = nuevo_nodo;
    }

    std::cout << "Cancion agregada exitosamente!\n";
}

// Mostrar playlist de inicio a fin

void mostrarPlaylist()
{
    std::cout << "\n--- Playlist (inicio -> fin) ---\n";

    if (inicio == nullptr)
    {
        std::cout << "La playlist esta vacia.\n";
        return;
    }

    Nodo *actual = inicio;
    int posicion = 1;

    while (actual != nullptr)
    {
        std::cout << "\nCancion #" << posicion << "\n";
        std::cout << "  Titulo: " << actual->cancion.titulo << "\n";
        std::cout << "  Artista: " << actual->cancion.artista << "\n";
        std::cout << "  Duracion: " << actual->cancion.duracion << " min ("
                  << clasificarDuracion(actual->cancion.duracion) << ")\n";
        std::cout << "  Genero: " << actual->cancion.genero << "\n";
        actual = actual->siguiente;
        posicion++;
    }
}

// Mostrar playlist de fin a inicio

void mostrarPlaylistInversa()
{
    std::cout << "\n--- Playlist (fin -> inicio) ---\n";

    if (fin == nullptr)
    {
        std::cout << "La playlist esta vacia.\n";
        return;
    }

    Nodo *actual = fin;
    int posicion = 1;

    while (actual != nullptr)
    {
        std::cout << "\nCancion #" << posicion << "\n";
        std::cout << "  Titulo: " << actual->cancion.titulo << "\n";
        std::cout << "  Artista: " << actual->cancion.artista << "\n";
        std::cout << "  Duracion: " << actual->cancion.duracion << " min ("
                  << clasificarDuracion(actual->cancion.duracion) << ")\n";
        std::cout << "  Genero: " << actual->cancion.genero << "\n";
        actual = actual->anterior;
        posicion++;
    }
}

// Buscar una canción por título

void buscarCancion(Cancion cancion)
{
    if (inicio == nullptr)
    {
        std::cout << "La playlist esta vacia.\n";
        return;
    }

    Nodo *actual = inicio;
    bool encontrada = false;

    while (actual != nullptr)
    {
        if (actual->cancion.titulo == cancion.titulo)
        {
            std::cout << "\nCancion encontrada:\n";
            std::cout << "  Titulo: " << actual->cancion.titulo << "\n";
            std::cout << "  Artista: " << actual->cancion.artista << "\n";
            std::cout << "  Duracion: " << actual->cancion.duracion << " min\n";
            std::cout << "  Genero: " << actual->cancion.genero << "\n";
            encontrada = true;
            break;
        }
        actual = actual->siguiente;
    }

    if (!encontrada)
    {
        std::cout << "Cancion no encontrada.\n";
    }
}

// Eliminar una canción por título

void eliminarCancion(Cancion cancion)
{
    if (inicio == nullptr)
    {
        std::cout << "La playlist esta vacia. No hay nada que eliminar.\n";
        return;
    }

    Nodo *actual = inicio;

    while (actual != nullptr)
    {
        if (actual->cancion.titulo == cancion.titulo)
        {
            // Caso 1: Un solo nodo
            if (actual == inicio && actual == fin)
            {
                inicio = nullptr;
                fin = nullptr;
            }
            // Caso 2: Nodo al inicio
            else if (actual == inicio)
            {
                inicio = inicio->siguiente;
                inicio->anterior = nullptr;
            }
            // Caso 3: Nodo al final
            else if (actual == fin)
            {
                fin = fin->anterior;
                fin->siguiente = nullptr;
            }
            // Caso 4: Nodo en medio
            else
            {
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;
            }

            delete actual;

            std::cout << "Cancion eliminada exitosamente!\n";
            return;
        }
        actual = actual->siguiente;
    }

    std::cout << "Cancion no encontrada.\n";
}

// Calcular duración total de la playlist

void calcularDuracionTotal()
{
    std::cout << "\n--- Duracion total de playlist ---\n";

    if (inicio == nullptr)
    {
        std::cout << "La playlist esta vacia. Duracion total: 0 min\n";
        return;
    }

    float duracion_total = 0;
    Nodo *actual = inicio;

    while (actual != nullptr)
    {
        duracion_total += actual->cancion.duracion;
        actual = actual->siguiente;
    }

    std::cout << "Duracion total: " << duracion_total << " minutos\n";
    std::cout << "Equivale a: " << (int)duracion_total << " min "
              << (int)((duracion_total - (int)duracion_total) * 60) << " segundos\n";
}

// Clasificar duración de una canción

std::string clasificarDuracion(float duracion)
{
    if (duracion < 3.0f)
    {
        return "Corta";
    }
    else if (duracion < 5.0f)
    {
        return "Media";
    }
    else
    {
        return "Larga";
    }
}

// Liberar memoria al salir del programa

void liberarMemoria()
{
    Nodo *actual = inicio;

    while (actual != nullptr)
    {
        Nodo *siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }

    inicio = nullptr;
    fin = nullptr;
    std::cout << "Memoria liberada. Hasta luego!\n";
}

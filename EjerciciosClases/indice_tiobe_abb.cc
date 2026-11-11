
#include <iostream>
#include <string>

struct Tiobe
{
    std::string lenguaje_programacion;
    float puntaje;
};

struct Nodo
{
    Tiobe inf_tiobe;
    Nodo *izquierdo;
    Nodo *derecho;
};

Nodo *CrearNodo(const Tiobe &inf_tiobe);
void InsertarNodo(Nodo *&abb, const Tiobe &inf_tiobe);

// Recorrido inorden
void ImprimirAscendente(Nodo *abb);

// Recorrido preorden
void ImprimirABB(Nodo *abb);

// Buscar un nodo
Nodo *BuscarNodo(Nodo *abb, float puntaje);

// Buscar el menor
Nodo *BuscarMenor(Nodo *abb);

// Borrar un nodo
void BorrarNodo(Nodo *&abb, float puntaje);

int main()
{
    Nodo *abb = nullptr;

    Tiobe inf_tiobe_1, inf_tiobe_2, inf_tiobe_3;

    inf_tiobe_1.lenguaje_programacion = "Python";
    inf_tiobe_1.puntaje = 9.0;

    inf_tiobe_2.lenguaje_programacion = "C";
    inf_tiobe_2.puntaje = 8.0;

    inf_tiobe_3.lenguaje_programacion = "C++";
    inf_tiobe_3.puntaje = 9.5;

    // Insertar nodos
    InsertarNodo(abb, inf_tiobe_1);
    InsertarNodo(abb, inf_tiobe_2);
    InsertarNodo(abb, inf_tiobe_3);

    // Imprimir de forma ascendente
    std::cout << "Imprimir el ABB de forma ascendente\n";
    ImprimirAscendente(abb);

    // Imprimir estructura del árbol
    std::cout << "\nImprimir la estructura actual del ABB\n";
    ImprimirABB(abb);

    // Buscar un lenguaje por su puntaje
    float buscar;
    std::cout << "\nIngresa el puntaje que deseas buscar: ";
    std::cin >> buscar;

    Nodo *encontrado = BuscarNodo(abb, buscar);

    if (encontrado != nullptr)
        std::cout << "Lenguaje encontrado: "
                  << encontrado->inf_tiobe.lenguaje_programacion << "\n";
    else
        std::cout << "Puntaje no encontrado\n";

    // Borrar un nodo
    float borrar;
    std::cout << "\nIngresa el puntaje que deseas borrar: ";
    std::cin >> borrar;

    BorrarNodo(abb, borrar);

    std::cout << "\nArbol despues de borrar:\n";
    ImprimirAscendente(abb);

    return 0;
}

// Crear un nodo
Nodo *CrearNodo(const Tiobe &inf_tiobe)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->inf_tiobe = inf_tiobe;
    nuevo_nodo->izquierdo = nullptr;
    nuevo_nodo->derecho = nullptr;
    return nuevo_nodo;
}

// Insertar un nodo
void InsertarNodo(Nodo *&abb, const Tiobe &inf_tiobe)
{
    if (abb == nullptr)
    {
        abb = CrearNodo(inf_tiobe);
        return;
    }

    if (inf_tiobe.puntaje < abb->inf_tiobe.puntaje)
        InsertarNodo(abb->izquierdo, inf_tiobe);
    else
        InsertarNodo(abb->derecho, inf_tiobe);
}

// Recorrido inorden
void ImprimirAscendente(Nodo *abb)
{
    if (abb == nullptr)
        return;

    ImprimirAscendente(abb->izquierdo);

    std::cout << "Lenguaje: "
              << abb->inf_tiobe.lenguaje_programacion
              << " [" << abb->inf_tiobe.puntaje << "]\n";

    ImprimirAscendente(abb->derecho);
}

// Recorrido preorden
void ImprimirABB(Nodo *abb)
{
    if (abb == nullptr)
        return;

    std::cout << "Lenguaje: "
              << abb->inf_tiobe.lenguaje_programacion
              << " [" << abb->inf_tiobe.puntaje << "]\n";

    ImprimirABB(abb->izquierdo);
    ImprimirABB(abb->derecho);
}

// Buscar un nodo
Nodo *BuscarNodo(Nodo *abb, float puntaje)
{
    if (abb == nullptr || abb->inf_tiobe.puntaje == puntaje)
        return abb;

    if (puntaje < abb->inf_tiobe.puntaje)
        return BuscarNodo(abb->izquierdo, puntaje);
    else
        return BuscarNodo(abb->derecho, puntaje);
}

// Buscar el nodo menor 
Nodo *BuscarMenor(Nodo *abb)
{
    while (abb->izquierdo != nullptr)
        abb = abb->izquierdo;

    return abb;
}

// Borrar un nodo
void BorrarNodo(Nodo *&abb, float puntaje)
{
    if (abb == nullptr)
        return;

    if (puntaje < abb->inf_tiobe.puntaje)
        BorrarNodo(abb->izquierdo, puntaje);

    else if (puntaje > abb->inf_tiobe.puntaje)
        BorrarNodo(abb->derecho, puntaje);

    else
    {
        Nodo *aux = abb;

        // Caso 1: Nodo sin hijos
        if (abb->izquierdo == nullptr && abb->derecho == nullptr)
            abb = nullptr;

        // Caso 2: Nodo con un solo hijo
        else if (abb->izquierdo == nullptr)
            abb = abb->derecho;

        else if (abb->derecho == nullptr)
            abb = abb->izquierdo;

        // Caso 3: Nodo con dos hijos
        else
        {
            Nodo *sucesor = BuscarMenor(abb->derecho);
            abb->inf_tiobe = sucesor->inf_tiobe;
            BorrarNodo(abb->derecho, sucesor->inf_tiobe.puntaje);
            return;
        }

        delete aux;
    }
}

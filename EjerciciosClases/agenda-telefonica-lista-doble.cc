#include <iostream>

struct Contacto
{
    std::string nombre_completo;
    std::string numero_telefono;
};

struct Nodo
{
    Contacto contacto;
    Nodo *siguiente;
    Nodo *anterior;
};

// Declaración de funciones con puntero doble (**)
void InsertarInicio(Nodo **lista, Contacto c);
void EliminarFinal(Nodo **lista);
void Imprimir(Nodo *lista);

int main()
{

    Nodo *lista = nullptr;

    Contacto c1, c2;

    c1.nombre_completo = "Mercedes Granados";
    c1.numero_telefono = "78721212";

    c2.nombre_completo = "Gerson Segovia";
    c2.numero_telefono = "78712212";


    InsertarInicio(&lista, c1);
    InsertarInicio(&lista, c2);
    Imprimir(lista);
    EliminarFinal(&lista);
    Imprimir(lista);

    return 0;
}

// Insertar al inicio
void InsertarInicio(Nodo **lista, Contacto c)
{
    struct Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->contacto = c; 
    nuevo_nodo->siguiente = *lista;
    nuevo_nodo->anterior = nullptr;

    // Si la lista no está vacía, actualizamos el puntero anterior del primer nodo actual
    if (*lista != nullptr)
    {
        (*lista)->anterior = nuevo_nodo;
    }

    // El nuevo nodo pasa a ser la cabeza de la lista
    *lista = nuevo_nodo;
}

// Eliminar el último nodo
void EliminarFinal(Nodo **lista)
{
    if (*lista == nullptr)
    {
        std::cout << "Lista vacia\n";
        return;
    }

    // Si solo hay un elemento
    if ((*lista)->siguiente == nullptr)
    {
        delete *lista;
        *lista = nullptr;
        return;
    }

    struct Nodo *temporal = *lista;
    while (temporal->siguiente != nullptr)
    {
        temporal = temporal->siguiente;
    }

    // Desconectamos el último nodo y lo borramos
    temporal->anterior->siguiente = nullptr;
    delete temporal;
}

// Imprimir la lista completa
void Imprimir(Nodo *lista)
{
    std::cout<<"\nImprimiendo lista .....\n";
     
    if (lista == nullptr)
    {
        std::cout << "Lista vacia\n";
        return;
    }

    struct Nodo *temporal = lista;
    while (temporal != nullptr)
    {
        std::cout << "Nombre: " << temporal->contacto.nombre_completo
                  << " - numero telefono: " << temporal->contacto.numero_telefono
                  << " | Dir: " << temporal
                  << " | Sig: " << temporal->siguiente
                  << " | Ant: " << temporal->anterior << "\n";
        temporal = temporal->siguiente;
    }
}
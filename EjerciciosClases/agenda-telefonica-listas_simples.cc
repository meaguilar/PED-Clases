#include <iostream>

struct Contacto
{
    std::string nombre;
    std::string telefono;
};

struct Nodo
{
    Contacto contacto;
    Nodo *siguiente;
};

// Puntero global
struct Nodo *lista = nullptr;

void InsertarInicio(Contacto c);
void InsertarFinal(Contacto c);
void EliminarInicio();
void EliminarFinal();
void Imprimir();

int main()
{
    Contacto contacto1, contacto2; 
    contacto1.nombre = "Julio";
    contacto1.telefono = "78923181";

    contacto2.nombre = "Sebastian";
    contacto2.telefono = "78923180";

    InsertarInicio(contacto1);
    InsertarFinal(contacto2);
    Imprimir();
    EliminarInicio();
    Imprimir();
    EliminarFinal();
    Imprimir();

    return 0;
}

void InsertarInicio(Contacto c)
{

    // Reserva de memoria
    struct Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->contacto.nombre = c.nombre;
    nuevo_nodo->contacto.telefono = c.telefono;

    if (lista == nullptr)
    {

        lista = nuevo_nodo;
    }
    else
    {
        nuevo_nodo->siguiente = lista;
        lista = nuevo_nodo;
    }
}

// Insertar al final
void InsertarFinal(Contacto c)
{
    struct Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->contacto.nombre = c.nombre;
    nuevo_nodo->contacto.telefono = c.telefono;

    nuevo_nodo->siguiente = nullptr;

    // Si la lista está vacía, el nuevo nodo es el primero
    if (lista == nullptr)
    {
        lista = nuevo_nodo;
        return;
    }

    // Si no está vacía, buscamos el último nodo
    struct Nodo *temporal = lista;
    while (temporal->siguiente != nullptr)
    {
        temporal = temporal->siguiente;
    }
    
    // Conectamos el último nodo con el nuevo
    temporal->siguiente = nuevo_nodo;
}


// Eliminar el primer nodo
void EliminarInicio()
{
    if (lista == nullptr)
    {
        std::cout << "Lista vacia\n";
        return;
    }

    // Guardamos el nodo a eliminar
    struct Nodo *temporal = lista;
    // La lista avanza al siguiente       
    lista = lista->siguiente;    
    // Liberamos memoria de forma segura        
    delete temporal;                  
}

// Eliminar el último nodo (sin variables confusas)
void EliminarFinal()
{
    if (lista == nullptr)
    {
        std::cout << "Lista vacia\n";
        return;
    }

    // Si solo hay un elemento, lo eliminamos directamente
    if (lista->siguiente == nullptr)
    {
        delete lista;
        lista = nullptr;
        return;
    }

    // Buscamos el penúltimo nodo
    struct Nodo *temporal = lista;
    while (temporal->siguiente->siguiente != nullptr)
    {
        temporal = temporal->siguiente;
    }

    // Borramos el último nodo y ponemos nullptr en el penúltimo
    delete temporal->siguiente;
    temporal->siguiente = nullptr;
}

void Imprimir()
{
    struct Nodo *temporal = lista;
    if (lista != nullptr)
    {
        while (temporal != nullptr)
        {
            std::cout << "Lista " << temporal->contacto.nombre << " Direccion " << temporal << " dir nodo siguiente " << temporal->siguiente << std::endl;
            temporal = temporal->siguiente;
        }
    }
    else
    {
        std::cout << "Lista vacia";
    }
}
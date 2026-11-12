#include <iostream>

const int kdimension = 7;

struct Persona
{
    std::string nombre;
    int valor_ascii;
};

struct Nodo
{
    Persona inf_persona;
    Nodo *anterior;
    Nodo *siguiente;
};

int FHash(int valor_ascii);
int GenerarASCII(std::string nombre);
void Agregar(Nodo *tabla[], Persona persona);
void Imprimir(Nodo *tabla[]);

int main()
{
    Persona inf_persona; 

    // Declaracion de la tabla hash local
    Nodo *tabla[kdimension] = {nullptr};

    inf_persona.nombre = "diego";
    inf_persona.valor_ascii = GenerarASCII(inf_persona.nombre);

    Agregar(tabla, inf_persona);

    Imprimir(tabla);

    return 0;
}

int GenerarASCII(std::string nombre)
{
    int suma_total = 0 ;
    for (char letra : nombre)
    {
        suma_total += static_cast<int>(letra);
    }
    
    return suma_total;
}

int FHash(int valor_ascii)
{
    return valor_ascii % kdimension;
}

void Agregar(Nodo *tabla[], Persona persona) {

    int clave = FHash(persona.valor_ascii);

    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->inf_persona = persona;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->siguiente = tabla[clave];

    if (tabla[clave] != nullptr) {
        tabla[clave]->anterior = nuevoNodo;
    }
    tabla[clave] = nuevoNodo;

    std::cout << "Persona agregada correctamente \n";
}

void Imprimir(Nodo *tabla[]) {

    for (int i = 0; i < kdimension; i++) {

        Nodo *temp = tabla[i];

        std::cout << "\n [Indice " << i << "]";

        if (temp == nullptr) {
            std::cout << " Vacio \n";
        }

        while (temp != nullptr) {

            std::cout << "\n  Nombre: "
                      << temp->inf_persona.nombre
                      << " | Valor ASCII: "
                      << temp->inf_persona.valor_ascii;
                     

            std::cout << "\n  Nodo: " << temp
                      << " | Anterior: " << temp->anterior
                      << " | Siguiente: " << temp->siguiente;

            temp = temp->siguiente;
        }

        std::cout << std::endl;
    }
}
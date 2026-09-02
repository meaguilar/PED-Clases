#include <iostream>

int incrementarValor(int valor);
int incrementarPuntero(int *valor);
int incrementarReferencia(int &valor);

int main()
{

    int numero = 2;

    // Declaración de puntero
    int *a = &numero;

    // Valor asignado a la variable
    std::cout << "Valor de la variable: " << numero << "\n";
    // Obtener el valor mediante el operador de desreferencia
    std::cout << "Valor mediante el puntero: " << *a << "\n";
    std::cout << "Dir. de memoria de la variable: " << a << " - " << &numero << "\n";

    
    std::cout << "Paso por valor: " << incrementarValor(numero) << "\n";
    std::cout << "Valor original de la variable: " << *a << "\n";
    
    // Modificación del valor asignado a la variable mediante el puntero
    std::cout << "Paso por puntero: " << incrementarPuntero(a) << "\n";
    std::cout << "Valor original de la variable: " << *a << "\n";

    // Modificación del valor asignado a la variable mediante la dir. de memoria 
    std::cout << "Paso por referencia: " << incrementarReferencia(numero) << "\n";
    std::cout << "Valor original de la variable: " << *a << "\n";
    return 0;
}

int incrementarValor(int valor)
{
    return ++valor;
}

int incrementarPuntero(int *valor)
{
    return ++(*valor);
}

int incrementarReferencia(int &valor)
{
    return ++valor;
}

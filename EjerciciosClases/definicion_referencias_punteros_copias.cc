#include <iostream>

int IncrementarValor(int x);
int IncrementarPuntero(int *x);
int IncrementarReferencia(int &x);

int main()
{

    int numero = 1;

    // Declaración de puntero
    int *ptr_numero = &numero;

    // Valor asignado a la variable
    std::cout << "Valor de la variable: " << numero << "\n";
    // Obtener el valor mediante el operador de desreferencia
    std::cout << "Valor mediante el puntero: " << *ptr_numero << "\n";
    std::cout << "Dir. de memoria de la variable: " << ptr_numero << " - " << &numero << "\n";
    std::cout << "Dir. de memoria del puntero: " << &ptr_numero << "\n";

    std::cout << "Paso por valor: " << IncrementarValor(numero) << "\n";
    std::cout << "Valor original de la variable: " << *ptr_numero << "\n";

    // Modificación del valor asignado a la variable mediante el puntero
    std::cout << "Paso por puntero: " << IncrementarPuntero(ptr_numero) << "\n";
    std::cout << "Valor original de la variable: " << *ptr_numero << "\n";

    // Modificación del valor asignado a la variable mediante la dir. de memoria
    std::cout << "Paso por referencia: " << IncrementarReferencia(numero) << "\n";
    std::cout << "Paso por referencia: " << IncrementarReferencia(*ptr_numero) << "\n";
    std::cout << "Valor original de la variable: " << *ptr_numero << "\n";

    return 0;
}

int IncrementarValor(int x)
{
    x += 10;
    return x;
}

int IncrementarPuntero(int *ptr_x)
{
    *ptr_x += 10;
    return *ptr_x;
}

int IncrementarReferencia(int &x)
{
    x += 10;
    return x;
}

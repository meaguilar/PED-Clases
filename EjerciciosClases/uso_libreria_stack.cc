#include <iostream>
#include <stack>

void Imprimir(std::stack<char> pila);

int main()
{

    std::stack<char> pila;

    pila.push('U');
    pila.push('C');
    pila.push('A');

    std::cout << "Cantidad de elementos " << pila.size() << "\n";

    Imprimir(pila);

    std::cout << "Cantidad de elementos " << pila.size() << "\n";

    return 0;
}

void Imprimir(std::stack<char> pila)
{
    while (!pila.empty())
    {
        std::cout << "Elementos de la pila "
                  << pila.top() << "\n";
        pila.pop();
    }
}
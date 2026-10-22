#include <iostream>

int CalcularFactorial(int x);
int CalcularPotencia(int base, int exp);
bool EsPar(int numero);
bool EsImpar(int numero);
int CalcularFibonacci(int n);

int main()
{
    int n = 5;
    int base = 2;
    int exp = 3;

    std::cout << "Factorial "
              << n << ": " << CalcularFactorial(n) << "\n";

    std::cout << "Potencia (" << "base: " << base << " exp: " << exp << "): " << CalcularPotencia(base, exp) << "\n";

    std::cout << "Fibonacci de " << n << ": " <<  CalcularFibonacci(n) << "\n";

    (EsPar(n)) ? std::cout << n << ": es par \n" : std::cout << n << ": es impar \n";

    return 0;
}

// Recursividad Directa 
int CalcularFactorial(int x)
{
    // Identificar el caso base/caso final
    if (x == 1 || x == 0)
    {
        return 1;
    }
    else
    {
        return x * CalcularFactorial(x - 1);
    }
}

int CalcularPotencia(int base, int exp)
{

    // caso base / final
    if (exp == 0)
    {
        return 1;
    }
    if (exp == 1)
    {
        return base;
    }
    else
    {
        return base * CalcularPotencia(base, exp - 1);
    }
}

int CalcularFibonacci(int n)
{

    // caso base
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return CalcularFibonacci(n - 1) + CalcularFibonacci(n - 2);
    }
}

// Recursividad indirecta
bool EsPar(int numero)
{
    // Caso base: 0 es par
    if (numero == 0)
    {
        return true;
    }
    else
    {
        return EsImpar(numero - 1);
    }
}

bool EsImpar(int numero)
{
    // Caso base
    if (numero == 0)
    {
        return false;
    }
    else
    {
        return EsPar(numero - 1);
    }
}

#include <iostream>

// Declaracion de las funciones 
void SolicitarDatos();
double CalcularSuperficie(double base, double altura);
void Imprimir(double superficie);
void Imprimir();

// Ambito global
double base;   
double altura; 

int main()
{
    double superficie = 0;

    // Llamado a la funcion de usuario
    SolicitarDatos();
    superficie = CalcularSuperficie(base, altura);
    Imprimir(superficie);

    // Funciones internas 
    std::cout<< "Peso en bytes de double:" << sizeof(base);

    return 0;
}

// Definicion de las funciones
void SolicitarDatos()
{
    std::cout << "Ingresar base:";
    std::cin >> base;
    std::cout << "Ingresar base:";
    std::cin >> altura;
}

double CalcularSuperficie(double base, double altura)
{
    return base * altura;
}

// Sobrecarga de funciones 

void Imprimir(double superficie)
{
    std::cout << "La superficie calculada: " << superficie << "/n";
}

void Imprimir(){

    std::cout<<"Probando la sobrecarga de funciones en C++";
}

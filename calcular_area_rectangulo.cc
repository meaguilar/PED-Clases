#include <iostream>

// Declaracion
void SolicitarDatos();
double CalcularSuperficie(double base, double altura);
void Imprimir(double superficie); 


int main()
{
    // Llamado a la funcion 
    

    return 0;
}

// Definicion
void SolicitarDatos(){
    // Variables de ambito local
    double base; 
    double altura; 

    std::cout<<"Ingresar base:";
    std::cin>>base;
    std::cout<<"Ingresar base:";
    std::cin>>altura;
}

double CalcularSuperficie(double base, double altura){
    return base * altura;
}

void Imprimir(double superficie){
    std::cout<<"La superficie calculada: " << superficie;
}

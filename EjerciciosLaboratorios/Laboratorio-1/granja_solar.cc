#include <iostream>

struct Bateria
{
    int carga;
};

// Declaración de funciones
void ConsultarCarga(int carga);
void CargarBateria(int &carga, int Wh);
void ConsumirEnergia(int *carga, int Wh);

int main()
{
    Bateria bateria;

    bateria.carga = 500;

    std::cout << "Carga inicial:" << std::endl;
    ConsultarCarga(bateria.carga);

    CargarBateria(bateria.carga, 200);

    std::cout << "Despues de cargar 200 Wh:" << std::endl;
    ConsultarCarga(bateria.carga);

    ConsumirEnergia(&bateria.carga, 150);

    std::cout << "Despues de consumir 150 Wh:" << std::endl;
    ConsultarCarga(bateria.carga);

    return 0;
}

// Implementación de funciones

// Paso por valor
void ConsultarCarga(int carga)
{
    std::cout << "Carga actual: " << carga << " Wh" << std::endl;
}

// Paso por referencia
void CargarBateria(int &carga, int Wh)
{
    carga += Wh;
}

// Paso por puntero
void ConsumirEnergia(int *carga, int Wh)
{
    *carga -= Wh;
}
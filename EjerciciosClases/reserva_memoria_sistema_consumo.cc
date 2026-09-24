#include <iostream>
#include <string>

// Simulador visualizar la reserva de memoria 
//https://lix.li/QxNoKw   

// Definicion variable global
float promedio_consumo;

// Definicion de la estructura
struct Consumo
{
    std::string nombre_mes;
    float kWh;
};

// Definicion de las funciones

void SolicitarDatos(Consumo *ptr);
void MostrarInformacion(Consumo *ptr);
float CalcularPromedioGeneralkWh(Consumo *ptr, int cant_mese);

int main()
{

    int cant_meses = 0;

    std::cout << "Ingresa la cantidad de meses a registrar: ";
    std::cin >> cant_meses;

    Consumo *ptr_consumo = new Consumo[cant_meses];

    for (int i = 0; i < cant_meses; i++)
    {

        SolicitarDatos(ptr_consumo + i);
        promedio_consumo = CalcularPromedioGeneralkWh(ptr_consumo + i, cant_meses);
    }
    for (int i = 0; i < cant_meses; i++)
    {
        MostrarInformacion(ptr_consumo + i);
    }

    std::cout << "\n Promedio de consumo kWh: " << promedio_consumo << "\n";

    // Liberar memoria 
    delete[] ptr_consumo;

    // Inicializar a nulo el puntero
    ptr_consumo = nullptr;

    return 0;
}

void SolicitarDatos(Consumo *ptr)
{

    std::cout << "Ingresa el nombre del mes: ";
    std::cin >> ptr->nombre_mes;

    std::cout << "Ingresa la cantidad de kilovatio consumidos (kWh): ";
    std::cin >> ptr->kWh;
}

void MostrarInformacion(Consumo *ptr)
{
    std::cout << "\n";
    std::cout << "\n Dir. memoria: " << ptr << "\n";
    std::cout << "Mes: " << ptr->nombre_mes;
    std::cout << " Dir. memoria: " << &ptr->nombre_mes << "\n";
    std::cout << "kWh: " << ptr->kWh;
    std::cout << " Dir. memoria: " << &ptr->kWh << "\n";
}

float CalcularPromedioGeneralkWh(Consumo *ptr, int cant_meses)
{
    float total_kWh;

    total_kWh += ptr->kWh;

    return total_kWh / cant_meses;
}
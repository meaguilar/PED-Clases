#include <iostream>
#include <random>

// Desde C++20 activa funcionalidades de calendario
#include <chrono>

// Lib de arreglo de tamaño variable
#include <vector>
#include <utility>
#include <string>

// Declaracion de Struct
struct DatosAlquiler
{
    const double kPrecioHora = 3;
    double costo_total;
    int codigo;
    std::vector<std::pair<std::string, float>> dias_horas;
};

struct Cliente
{
    std::string nombre_completo;
    int anio_nac;
    unsigned mes_nac;
    unsigned dia_nac;
    int edad;
    std::string num_telefono;

    // Variable que anida
    DatosAlquiler datos_alquiler;
};

// Variable global
Cliente cliente;

// Variable vector
std::vector<Cliente> vector_clientes;

// Declaracion de funciones
void SolicitarDatos();
float CalcularCostoAlquiler(std::vector<std::pair<std::string, float>> dias_horas, float precio_hora);
int GenerarCodigoAlquiler();
void DeterminarDescuento(int cod_alquiler);
void Imprimir();
int CalcularEdad(int anio, unsigned mes, unsigned dia);

int main()
{
    std::cout << "Tamano en bytes de struct cliente: " << sizeof(cliente) << "\n";

    SolicitarDatos();

    cliente.datos_alquiler.costo_total =
        CalcularCostoAlquiler(cliente.datos_alquiler.dias_horas, cliente.datos_alquiler.kPrecioHora);

    // Generar codigo
    cliente.datos_alquiler.codigo = GenerarCodigoAlquiler();

    // Agregar cliente al vector
    vector_clientes.push_back(cliente);

    // Imprimir datos
    Imprimir();

    return 0;
}

void SolicitarDatos()
{
    std::string dias;
    float cant_horas;

    std::cout << "Ingresa el nombre: ";
    std::cin >> cliente.nombre_completo;

    std::cout << "\nFecha de nacimiento (2000 09 01)\n";

    std::cout << "Ingresa el anio (2000): ";
    std::cin >> cliente.anio_nac;

    std::cout << "Ingresa el mes (09): ";
    std::cin >> cliente.mes_nac;

    std::cout << "Ingresa el dia (01): ";
    std::cin >> cliente.dia_nac;

    // Calcular edad
    cliente.edad = CalcularEdad(cliente.anio_nac, cliente.mes_nac, cliente.dia_nac);

    std::cout << "Ingresa el numero de telefono: ";
    std::cin >> cliente.num_telefono;
    std::cout << "Detalles para el alquiler: \n";
    std::cout << "Ingresar el dia (Miercoles): ";
    std::cin >> dias;
    std::cout << "Ingresar horas de alquiler para ese dia: ";
    std::cin >> cant_horas;

    // Guardar dia y horas de alquiler en el vector-pair
    cliente.datos_alquiler.dias_horas.push_back({dias, cant_horas});
}

float CalcularCostoAlquiler(std::vector<std::pair<std::string, float>> dias_horas, float precio_hora)
{
    // Calcular el costo total
    float total_horas = 0;

    for (int i = 0; i < cliente.datos_alquiler.dias_horas.size(); i++)
    {
        total_horas += cliente.datos_alquiler.dias_horas[i].second;
    }
    return total_horas * precio_hora;
}

int GenerarCodigoAlquiler()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(1000, 9999);

    return dist(gen);
}

void DeterminarDescuento(int cod_alquiler)
{
    (cod_alquiler % 2 == 0) ? std::cout << "Descuento del 10%\n" : std::cout << "No tiene descuento\n";
}

void Imprimir()
{
    std::cout << "\n";
    std::cout << "\n............Imprimiendo datos................. \n";

    for (int i = 0; i < vector_clientes.size(); i++)
    {
        std::cout << "Nombre del cliente: " << vector_clientes[i].nombre_completo << "\n";

        std::cout << "Fecha de nacimiento: " << vector_clientes[i].anio_nac << "-"
                  << vector_clientes[i].mes_nac << "-"
                  << vector_clientes[i].dia_nac << "\n";

        std::cout << "Edad: " << vector_clientes[i].edad << "\n";

        std::cout << "Telefono: " << vector_clientes[i].num_telefono << "\n";

        std::cout << "Precio por hora: $" << vector_clientes[i].datos_alquiler.kPrecioHora << "\n";

        std::cout << "Detalles de horas de alquiler:\n";

        for (int j = 0; j < vector_clientes[i].datos_alquiler.dias_horas.size(); j++)
        {
            std::cout << " - Dia de alquiler: "
                      << vector_clientes[i].datos_alquiler.dias_horas[j].first << "\n";

            std::cout << " - Horas de alquiler: "
                      << vector_clientes[i].datos_alquiler.dias_horas[j].second << "\n";
        }

        std::cout << "Costo de alquiler: $"
                  << vector_clientes[i].datos_alquiler.costo_total << "\n";

        std::cout << "Codigo de alquiler: "
                  << vector_clientes[i].datos_alquiler.codigo << "\n";

        DeterminarDescuento(vector_clientes[i].datos_alquiler.codigo);

        std::cout << "\n";
    }
}

int CalcularEdad(int anio, unsigned mes, unsigned dia)
{
    // Obtener fecha actual
    auto hoy =
        std::chrono::floor<std::chrono::days>(
            std::chrono::system_clock::now());

    // Obtener año, mes y dia actual
    std::chrono::year_month_day fechaActual{hoy};

    int edad =
        int(fechaActual.year()) - anio;

    // Verificar si todavía no ha cumplido años
    if (unsigned(fechaActual.month()) < mes || (unsigned(fechaActual.month()) == mes && unsigned(fechaActual.day()) < dia))
    {
        --edad;
    }

    return edad;
}

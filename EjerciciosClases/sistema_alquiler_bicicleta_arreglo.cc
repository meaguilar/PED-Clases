#include <iostream>
#include <random>

// Desde C++20 activa funcionalidades de calendario 
#include <chrono>

// #include <cstdlib>
// #include <ctime>

// Declaracion de Struct
struct DatosAlquiler
{
    float horas_alquiler[3];
    float costo_alquiler;
    int cod_alquiler;
    const float KPrecioHora = 3.0;
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
    struct DatosAlquiler datos_alquiler;

} cliente[3];

// Declaracion de funciones
void SolicitarDatos();
float CalcularCostoAlquiler(float cant_horas[], float precio_hora);
int GenerarCodigoAlquiler();
void DeterminarDescuento(int cod_alquiler);
void Imprimir();
int CalcularEdad(int anio, unsigned mes, unsigned dia);

int CalcularLongitudArreglo();

int main()
{
    std::cout << "Tamano en bytes de struct Cliente: " << sizeof(cliente) << "\n";

    SolicitarDatos();

    for (int i = 0; i < 3; i++)
    {
        cliente[i].datos_alquiler.costo_alquiler =
            CalcularCostoAlquiler(cliente[i].datos_alquiler.horas_alquiler, cliente[i].datos_alquiler.KPrecioHora);
        cliente[i].datos_alquiler.cod_alquiler = GenerarCodigoAlquiler();
    }

    Imprimir();

    return 0;
}

void SolicitarDatos()
{

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Ingresa el nombre: ";
        std::cin >> cliente[i].nombre_completo;
        std::cout << "Fecha de nacimiento (2000 09 01) \n";
        std::cout << "Ingresa el anio (2000): ";
        std::cin >> cliente[i].anio_nac;
        std::cout << "Ingresa el mes (09): ";
        std::cin >> cliente[i].mes_nac;
        std::cout << "Ingresa el dia (01): ";
        std::cin >> cliente[i].dia_nac;
        cliente[i].edad = CalcularEdad(cliente[i].anio_nac, cliente[i].mes_nac, cliente[i].dia_nac);
        std::cout << "Ingresa el numero de telefono: ";
        std::cin >> cliente[i].num_telefono;

        for (int j = 0; j < CalcularLongitudArreglo(); j++)
        {
            std::cout << "Ingresar horas de alquiler: ";
            std::cin >> cliente[i].datos_alquiler.horas_alquiler[j];
        }
    }
}

float CalcularCostoAlquiler(float cant_horas[], float precio_hora)
{
    float total_horas_alquiler = 0;
    for (int i = 0; i < CalcularLongitudArreglo(); i++)
    {
        total_horas_alquiler += cant_horas[i];
    }

    return total_horas_alquiler * precio_hora;
}

int GenerarCodigoAlquiler()
{
    /* srand(time(0));
     return rand() % 9999 + 1000;
     */

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(1000, 9999);
    return dist(gen);
}

void DeterminarDescuento(int cod_alquiler)
{
    /*  if (cod_alquiler % 2 == 0)
      {
          std::cout<<"Descuento del 10%";
      }else{
          std::cout<<"No tiene descuento";
      }
          */
    // Implementacion del operador ternario
    (cod_alquiler % 2 == 0) ? std::cout << "Descuento del 10% \n" : std::cout << "No tiene descuento \n";
}

void Imprimir()
{
    std::cout << "\n";
    std::cout << "\n ............Imprimiendo datos.................. \n";

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Nombre del cliente: " << cliente[i].nombre_completo << "\n";
        std::cout << "Fecha de nacimiento: " << cliente[i].anio_nac << "-" << cliente[i].mes_nac << "-" << cliente[i].dia_nac << "\n";
        std::cout << "Edad: " << cliente[i].edad << " años" << "\n";
        std::cout << "Telefono: " << cliente[i].num_telefono << "\n";
        std::cout << "Precio por hora: $" << cliente[i].datos_alquiler.KPrecioHora << "\n";
        std::cout << "Detalles de horas de alquiler: \n";
        for (int j = 0; j < CalcularLongitudArreglo(); j++)
        {
            std::cout << " - Horas alquiler: " << cliente[i].datos_alquiler.horas_alquiler[j] << "\n";
        }

        std::cout << "Costo de alquiler: $" << cliente[i].datos_alquiler.costo_alquiler << "\n";
        std::cout << "Codigo de alquiler: " << cliente[i].datos_alquiler.cod_alquiler << "\n";
        DeterminarDescuento(cliente[i].datos_alquiler.cod_alquiler);
        std::cout << "\n";
    }
}

int CalcularEdad(int anio, unsigned mes, unsigned dia)
{

    // using namespace std::chrono;

    // Obtener la fecha y hora actual
    auto hoy = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());

    // Obtener la fecha separada en año, mes y dia
    std::chrono::year_month_day fechaActual{hoy};

    int edad = int(fechaActual.year()) - anio;

    // Todavia no ha cumplido años durante el año actual
    if (unsigned(fechaActual.month()) < mes || (unsigned(fechaActual.month()) == mes && unsigned(fechaActual.day()) < dia))
    {
        --edad;
    }

    return edad;
}

int CalcularLongitudArreglo()
{

    int longitud = 0;
    for (int i = 0; i < 3; i++)
    {
        longitud = sizeof(cliente[i].datos_alquiler.horas_alquiler) / sizeof(float);
    }

    return longitud;
}

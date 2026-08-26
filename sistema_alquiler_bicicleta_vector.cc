#include <iostream>
// #include <cstdlib>
// #include <ctime>
#include <random>

// Desde C++20 activa funcionalidades de calendario 
#include <chrono>

// Lib de arreglo de tamaño variable
#include <vector>

struct DatosAlquiler
{
    const double kPrecioAlquiler = 3;
    double costo_alquiler;
    int cod_alquiler;
    double horas_alquiler[3];
};

// Struct Principal
struct Cliente
{
    std::string nombre;
    int edad;
    int anio_nac;
    std::string num_telefono;
    // Variable que anida
    struct DatosAlquiler datos_alquiler;

} cliente; // Variable de ámbito global

// Declaracion de un vector
std::vector<struct Cliente> vector_clientes;

// Declaracion de funciones
void SolicitarDatos();
double CalcularCostoAlquiler(double arreglo_horas[], double precio_alquier);
int GenerarCodigoCupon();
void DeterminarDescuento(double cod_alquiler);
void Imprimir();
int DeterminarLongitudArreglo();
int CalcularEdad(int anio, unsigned mes, unsigned dia);

int main()
{

    std::cout << " Tamano del struct cliente" << sizeof(cliente) << "\n";

    SolicitarDatos();

    cliente.datos_alquiler.costo_alquiler =
        CalcularCostoAlquiler(cliente.datos_alquiler.horas_alquiler, cliente.datos_alquiler.kPrecioAlquiler);

    cliente.datos_alquiler.cod_alquiler = GenerarCodigoCupon();

    // Almacenando en el vector 
    vector_clientes.push_back(cliente);

    Imprimir();

    return 0;
}

void SolicitarDatos()
{

    std::cout << "Ingresar el nombre:";
    std::cin >> cliente.nombre;
    // Modificar que se guarde en el arreglo de 3 espacios
    for (int j = 0; j < DeterminarLongitudArreglo(); j++)
    { 
        std::cout << "Ingresa las horas de alquiler ";
        std::cin >> cliente.datos_alquiler.horas_alquiler[j];
    }
}

double CalcularCostoAlquiler(double arreglo_horas[], double precio_alquier)
{
    double cantidad_horas = 0;

    for (int i = 0; i < DeterminarLongitudArreglo(); i++)
    {
        cantidad_horas += arreglo_horas[i];
    }

    return cantidad_horas * precio_alquier;
}

int GenerarCodigoCupon()
{
    /*  srand(time(NULL));
      // rango 1000 - 9999
      return rand() %  9999 - 1000 + 1;
  */

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1000, 9999);

    return dist(gen);
}

void DeterminarDescuento(int cod_alquiler)
{

    /* if (cod_alquiler % 2 == 0)
     {
         std::cout << "Descuento del 10% \n";
     }
     else
     {
         std::cout << "No tiene descuento \n";
     }*/

    // Operador ternario
    (cod_alquiler % 2 == 0) ? std::cout << "Descuento del 10% \n"
                            : std::cout << "No tiene descuento \n";
}

void Imprimir()
{

    std::cout << "\n............Imprimiendo datos................. \n";

    for (int i = 0; i < vector_clientes.size(); i++)
    {
        std::cout << "Nombre cliente: " << vector_clientes[i].nombre << "\n";
        std::cout << "Precio alquiler por hora $" << vector_clientes[i].datos_alquiler.kPrecioAlquiler << "\n";
        std::cout << "Detalle de horas de alquiler \n";

        for (int j = 0; j < DeterminarLongitudArreglo(); j++)
        {
            std::cout << " - Cantidad de horas de alquiler: " << vector_clientes[i].datos_alquiler.horas_alquiler[j] << "\n";
        }

        std::cout << "Costo de alquiler: $" << vector_clientes[i].datos_alquiler.costo_alquiler << "\n";
        std::cout << "Codigo de alquiler: " << vector_clientes[i].datos_alquiler.cod_alquiler << "\n";
        DeterminarDescuento(vector_clientes[i].datos_alquiler.cod_alquiler);
    }
}

int DeterminarLongitudArreglo()
{
    int longitud;
   
    longitud = sizeof(cliente.datos_alquiler.horas_alquiler) / sizeof(double);

    return longitud;
}

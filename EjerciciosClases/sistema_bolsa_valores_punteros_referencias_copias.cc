#include <iostream>
#include <random>
#include <chrono>  
#include <thread>

struct Accion
{
    // Simbolo bursatil de la empresa Ejemplo Amazon AMZN
    std::string simbolo_bursatil;
    std::string nombre_empresa;
    // Precio al que se adquiere
    float precio_compra;
    // Precio al que se oferta 
    float precio_venta;
    // Ultimo precio cotizado en el mercado
    float ultimo_precio;
};

float CalcularMargenCompraVenta(float precio_venta, float precio_compra);
// Sobrecarga de funciones 
void SimularFluctuacionPrecios(Accion &accion);
void SimularFluctuacionPrecios(Accion *accion);


int main()
{
    Accion miAccion;
    miAccion.simbolo_bursatil = "AMZN";

   
    std::cout << "Monitoreando la accion: " << miAccion.simbolo_bursatil << "\n";
    std::cout << "Actualizando cada 10 segundos.....\n\n";


    while (true) {

        // Simular el mercado de precios de las acciones
        SimularFluctuacionPrecios(miAccion);

        // Imprimir
        std::cout << "Ticker: " << miAccion.simbolo_bursatil << std::endl;
        std::cout << "Precio Compra: $" << miAccion.precio_compra << std::endl;
        std::cout << "Precio Venta:  $" << miAccion.precio_venta << std::endl;

        miAccion.ultimo_precio = CalcularMargenCompraVenta(miAccion.precio_compra, miAccion.precio_venta);
        std::cout << "Margen/ganancia: $" << miAccion.ultimo_precio << std::endl;

        // Pausa secuencial de 10 segundos
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    return 0;
}

// Función para calcular margen de la ganancia 
float CalcularMargenCompraVenta(float precio_venta, float precio_compra)
{
    return precio_venta - precio_compra;
}

void SimularFluctuacionPrecios(Accion &accion)
{
    // Generador de números pseudoaleatorios basado en hardware (semilla aleatoria)
    std::random_device rd;
    std::mt19937 gen(rd());

    // Definimos el rango para el precio de compra 
    std::uniform_real_distribution<double> distribucionPrecio(10.0, 500.0);

    // Definimos un rango para el margen de compra venta
    std::uniform_real_distribution<double> distribucionMargen(0.05, 1.50);

    // Asignamos los valores aleatorios a la estructura
    accion.precio_compra = distribucionPrecio(gen);
    accion.precio_venta = accion.precio_compra + distribucionMargen(gen);
}

void SimularFluctuacionPrecios(Accion *accion){

    // Generador de números pseudoaleatorios basado en hardware (semilla aleatoria)
    std::random_device rd;
    std::mt19937 gen(rd());

    // Definimos el rango para el precio de compra 
    std::uniform_real_distribution<double> distribucionPrecio(10.0, 500.0);

    // Definimos un pequeño rango para el margen de compra venta
    std::uniform_real_distribution<double> distribucionMargen(0.05, 1.50);


    // Asignamos los valores aleatorios a la estructura usando el operador ->
    accion->precio_compra = distribucionPrecio(gen);
    accion->precio_venta = accion->precio_compra + distribucionMargen(gen);
}
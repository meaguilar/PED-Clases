#include <iostream>
#include <queue>
#include <chrono>
#include <thread>

struct Documento
{
    std::string nombre_archivo;
    int cantidad_paginas;
    // Vertical / Horizontal
    std::string orientacion;
    // Campo adicional

    // Campo calculado
    float tiempo_impresion;
};

// Funcion para solicitar los datos
struct Documento SolicitarDatos(Documento &doc);
void Imprimir(std::queue<Documento> cola_impresion);
void CalcularTiempoImpresion(Documento &doc);

int main()
{

    std::queue<Documento> cola_impresion;
    struct Documento documento_imprimir;
    char continuar;

    do
    {
        SolicitarDatos(documento_imprimir);
        CalcularTiempoImpresion(documento_imprimir);

        // Almacenar los datos en la cola
        cola_impresion.push(documento_imprimir);

        std::cout << "Documentos en cola: "
                  << cola_impresion.size() << "\n";

        std::cout << "Deseas agregar otro documento a la cola impresion (s/n): ";
        std::cin >> continuar;

    } while (continuar == 's');

    Imprimir(cola_impresion);

    return 0;
}

struct Documento SolicitarDatos(Documento &doc)
{

    std::cout << "Ingresa el nombre del archivo a imprimir: ";
    std::cin >> doc.nombre_archivo;
    std::cout << "Cantidad de paginas del archivo: ";
    std::cin >> doc.cantidad_paginas;

    return doc;
}

void Imprimir(std::queue<Documento> cola_impresion)
{
    // Recorrer la cola
    std::cout << "\nImprimiendo documentos en cola \n";

    while (!cola_impresion.empty())
    {
        std::cout << "\nNombre del archivo: "
                  << cola_impresion.front().nombre_archivo;
        std::cout << "\nCantidad de paginas: "
                  << cola_impresion.front().cantidad_paginas;
        std::cout << "\nTiempo de impresion: "
                  << cola_impresion.front().tiempo_impresion
                  << " segundos.";

        std::cout << "\n Imprimiendo...\n";

        std::this_thread::sleep_for(
            std::chrono::seconds(
                static_cast<int>(cola_impresion.front().tiempo_impresion)
            )
        );
        
        std::cout << "Documento impreso.\n";
        // Elimina el documento que está al frente
        cola_impresion.pop();
    }
}

void CalcularTiempoImpresion(Documento &doc)
{
    doc.tiempo_impresion = doc.cantidad_paginas * 5.0;
}
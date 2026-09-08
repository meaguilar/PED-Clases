#include <chrono> //tiempo
#include <iostream>
#include <random> //aleatorio
#include <thread> //multiples hilos

// Struct anidado.
struct EstadisticasRed
{
    double enviado;
    double recibido;
};

struct AdaptadorRed
{
    std::string nombre;
    std::string direccion_ip;
    std::string tipo_conexion;
    EstadisticasRed stats;
};

// Declaración de funciones.
void ConsultarEstado(const AdaptadorRed &adaptador);
void RegistrarActividad(AdaptadorRed &adaptador, double envio,
                        double recepcion);
void RegistrarActividad(AdaptadorRed *adaptador, double envio,
                        double recepcion);

int main()
{
    AdaptadorRed wifi;

    wifi.nombre = "Wi-Fi";
    wifi.direccion_ip = "192.168.1.15";
    wifi.tipo_conexion = "Inalambrico";
    wifi.stats.enviado = 0;
    wifi.stats.recibido = 0;

    // Generador de números aleatorios.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(5.0, 50.0);

    std::cout << "Estado inicial:" << std::endl;
    ConsultarEstado(wifi);

    for (int i = 1; i <= 5; ++i)
    {
        // Simula un refresco cada 1 segundo.
        std::this_thread::sleep_for(std::chrono::seconds(1));

        double kb_envio = dist(gen);
        double kb_recepcion = dist(gen);

        if (i % 2 == 0)
        {
            // Usa la sobrecarga por referencia.
            RegistrarActividad(wifi, kb_envio, kb_recepcion);
        }
        else
        {
            // Usa la sobrecarga por puntero.
            RegistrarActividad(&wifi, kb_envio, kb_recepcion);
        }

        std::cout << "\n--- Actualizacion " << i << " ---" << std::endl;
        ConsultarEstado(wifi);
    }

    return 0;
}

// Consulta el estado del adaptador.
// Se utiliza referencia constante porque la función no modifica
// los datos del adaptador.
void ConsultarEstado(const AdaptadorRed &adaptador)
{
    std::cout << "Adaptador: " << adaptador.nombre
              << " | IP: " << adaptador.direccion_ip
              << " | Tipo: " << adaptador.tipo_conexion << std::endl;

    std::cout << "Enviado: " << adaptador.stats.enviado
              << " KB | Recibido: " << adaptador.stats.recibido << " KB"
              << std::endl;
}

// Sobrecarga por referencia.
// Modifica directamente el adaptador recibido.
void RegistrarActividad(AdaptadorRed &adaptador, double envio,
                        double recepcion)
{
    adaptador.stats.enviado += envio;
    adaptador.stats.recibido += recepcion;
}

// Sobrecarga por puntero.
// Modifica el adaptador mediante su dirección de memoria.
void RegistrarActividad(AdaptadorRed *adaptador, double envio,
                        double recepcion)
{
    if (adaptador == nullptr)
    {
        return;
    }

    adaptador->stats.enviado += envio;
    adaptador->stats.recibido += recepcion;
}

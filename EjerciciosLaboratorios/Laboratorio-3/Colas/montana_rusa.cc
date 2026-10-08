
#include <iostream>
#include <queue>
#include <string>

// Almacena los datos de cada pasajero.
struct Persona {
    std::string nombre;
    int numero_asiento;
    std::string categoria;
};

// Registra una persona y le asigna un asiento consecutivo.
void AgregarPersona(std::queue<Persona>& cola, int& siguiente_asiento) {
    Persona nueva_persona;

    std::cout << "Ingrese el nombre del pasajero: ";
    std::getline(std::cin, nueva_persona.nombre);

    std::cout << "Ingrese la categoria (adulto, nino, etc.): ";
    std::getline(std::cin, nueva_persona.categoria);

    nueva_persona.numero_asiento = siguiente_asiento;

    cola.push(nueva_persona);
    siguiente_asiento++;

    std::cout << "Pasajero registrado. Asiento asignado: "
              << nueva_persona.numero_asiento << "\n";
}

// Muestra los pasajeros sin modificar la cola original.
void MostrarCola(std::queue<Persona> cola) {
    if (cola.empty()) {
        std::cout << "No hay personas esperando para subir.\n";
        return;
    }

    std::cout << "\n--- Pasajeros en espera ---\n";

    while (!cola.empty()) {
        Persona actual = cola.front();

        std::cout << "Nombre: " << actual.nombre << "\n";
        std::cout << "Asiento: "
                  << actual.numero_asiento << "\n";
        std::cout << "Categoria: " << actual.categoria << "\n";
        std::cout << "--------------------------\n";

        cola.pop();
    }
}

// Atiende hasta cinco pasajeros para iniciar un viaje.
void IniciarViaje(std::queue<Persona>& cola) {
    if (cola.empty()) {
        std::cout << "No hay pasajeros para iniciar el viaje.\n";
        return;
    }

    const int capacidad_viaje = 5;
    int pasajeros_abordados = 0;

    std::cout << "\n--- Pasajeros que suben al viaje ---\n";

    while (!cola.empty() && pasajeros_abordados < capacidad_viaje) {
        Persona pasajero = cola.front();

        std::cout << "Nombre: " << pasajero.nombre << "\n";
        std::cout << "Asiento: "
                  << pasajero.numero_asiento << "\n";
        std::cout << "Categoria: " << pasajero.categoria << "\n";
        std::cout << "--------------------------\n";

        cola.pop();
        pasajeros_abordados++;
    }

    std::cout << "Total de pasajeros que subieron: "
              << pasajeros_abordados << "\n";

    if (cola.empty()) {
        std::cout << "No quedan pasajeros en espera.\n";
    } else {
        std::cout << "Quedan " << cola.size()
                  << " pasajeros esperando.\n";
    }
}

int main() {
    std::queue<Persona> cola;
    int siguiente_asiento = 1;
    int opcion;

    do {
        std::cout << "\n=== Sistema de montana rusa ===\n";
        std::cout << "1. Agregar persona\n";
        std::cout << "2. Mostrar cola\n";
        std::cout << "3. Iniciar viaje\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";

        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Ingrese una opcion valida.\n";
            continue;
        }

        std::cin.ignore(1000, '\n');

        switch (opcion) {
            case 1:
                AgregarPersona(cola, siguiente_asiento);
                break;

            case 2:
                MostrarCola(cola);
                break;

            case 3:
                IniciarViaje(cola);
                break;

            case 0:
                std::cout << "Cerrando el sistema.\n";
                break;

            default:
                std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}
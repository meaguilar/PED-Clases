#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

struct Persona {
  std::string nombre;
  std::string identificacion;
};

bool SolicitarDatosPersona(Persona& persona);
void BuscarCasillero(const std::unordered_map<int, Persona>& casilleros, int numero);
void MostrarCasilleros(const std::unordered_map<int, Persona>& casilleros);

int main() {
  int opcion = 0;
  int numero = 0;
  Persona persona_temporal;

  // Clave: numero del casillero - Valor: datos de la persona asignada
  std::unordered_map<int, Persona> casilleros;

  do {
    std::cout << "\n=== Sistema de Casilleros Inteligentes (std::unordered_map) ===\n";
    std::cout << "1. Asignar casillero\n";
    std::cout << "2. Buscar casillero\n";
    std::cout << "3. Liberar casillero\n";
    std::cout << "4. Mostrar casilleros ocupados\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    switch (opcion) {
      case 1: {
        std::cout << "Ingrese el numero del casillero: ";
        std::cin >> numero;
        if (numero <= 0) {
          std::cout << "Error: El numero del casillero debe ser un entero positivo.\n";
          break;
        }

        if (casilleros.count(numero) > 0) {
          std::cout << "Aviso: El casillero " << numero
                    << " ya esta ocupado. No se permiten claves duplicadas.\n";
          break;
        }

        if (!SolicitarDatosPersona(persona_temporal)) {
          std::cout << "Error: Los datos de la persona no pueden estar vacios.\n";
          break;
        }

        casilleros.insert({numero, persona_temporal});
        std::cout << "Casillero " << numero << " asignado correctamente a "
                  << persona_temporal.nombre << ".\n";
        break;
      }

      case 2:
        if (casilleros.empty()) {
          std::cout << "No hay casilleros ocupados. Todos estan disponibles.\n";
          break;
        }

        std::cout << "Ingrese el numero del casillero a buscar: ";
        std::cin >> numero;
        if (numero <= 0) {
          std::cout << "Error: El numero del casillero debe ser un entero positivo.\n";
          break;
        }

        BuscarCasillero(casilleros, numero);
        break;

      case 3:
        if (casilleros.empty()) {
          std::cout << "No hay casilleros ocupados para liberar.\n";
          break;
        }

        std::cout << "Ingrese el numero del casillero a liberar: ";
        std::cin >> numero;
        if (numero <= 0) {
          std::cout << "Error: El numero del casillero debe ser un entero positivo.\n";
          break;
        }

        // erase() devuelve la cantidad de elementos eliminados (0 o 1)
        if (casilleros.erase(numero) > 0) {
          std::cout << "Casillero " << numero << " liberado correctamente.\n";
        } else {
          std::cout << "Aviso: El casillero " << numero
                    << " no esta ocupado. No se puede liberar.\n";
        }
        break;

      case 4:
        if (casilleros.empty()) {
          std::cout << "No hay casilleros ocupados.\n";
        } else {
          MostrarCasilleros(casilleros);
        }
        break;

      case 0:
        std::cout << "Saliendo del programa...\n";
        break;

      default:
        std::cout << "Opcion no valida. Intente de nuevo.\n";
        break;
    }
  } while (opcion != 0);

  return 0;
}

bool SolicitarDatosPersona(Persona& persona) {
  std::cin.ignore();

  std::cout << "Ingrese el nombre de la persona: ";
  std::getline(std::cin, persona.nombre);

  std::cout << "Ingrese la identificacion de la persona: ";
  std::getline(std::cin, persona.identificacion);

  return !persona.nombre.empty() && !persona.identificacion.empty();
}

void BuscarCasillero(const std::unordered_map<int, Persona>& casilleros,
                     int numero) {
  auto iterador = casilleros.find(numero);

  if (iterador != casilleros.end()) {
    std::cout << "Casillero " << iterador->first << " OCUPADO -> Nombre: "
              << iterador->second.nombre
              << " - Identificacion: " << iterador->second.identificacion
              << "\n";
  } else {
    std::cout << "El casillero " << numero << " esta disponible.\n";
  }
}

void MostrarCasilleros(const std::unordered_map<int, Persona>& casilleros) {
  std::cout << "\n--- Casilleros Ocupados (std::unordered_map - Sin orden) ---\n";
  int contador = 1;

  std::for_each(casilleros.begin(), casilleros.end(),
                [&contador](const auto& entrada) {
                  std::cout << contador++ << ". Casillero " << entrada.first
                            << " - Nombre: " << entrada.second.nombre
                            << " - Identificacion: "
                            << entrada.second.identificacion << "\n";
                });
}

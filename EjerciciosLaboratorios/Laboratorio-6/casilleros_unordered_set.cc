#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

struct Persona {
  std::string nombre;
  std::string identificacion;
};

struct Casillero {
  int numero;
  Persona persona;

  // Dos casilleros son iguales si tienen el mismo numero
  bool operator==(const Casillero& otro) const {
    return numero == otro.numero;
  }
};

// Funcion hash propia: el hash se obtiene solo del numero del casillero
struct CasilleroHash {
  std::size_t operator()(const Casillero& casillero) const {
    return std::hash<int>()(casillero.numero);
  }
};

bool SolicitarDatosPersona(Persona& persona);
void BuscarCasillero(const std::unordered_set<Casillero, CasilleroHash>& casilleros,
                     int numero);
void MostrarCasilleros(const std::unordered_set<Casillero, CasilleroHash>& casilleros);

int main() {
  int opcion = 0;
  int numero = 0;
  Casillero casillero_temporal;

  // Conjunto de casilleros ocupados, sin numeros duplicados
  std::unordered_set<Casillero, CasilleroHash> casilleros;

  do {
    std::cout << "\n=== Sistema de Casilleros Inteligentes (std::unordered_set) ===\n";
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

        casillero_temporal.numero = numero;
        if (casilleros.count(casillero_temporal) > 0) {
          std::cout << "Aviso: El casillero " << numero
                    << " ya esta ocupado. No se permiten duplicados.\n";
          break;
        }

        if (!SolicitarDatosPersona(casillero_temporal.persona)) {
          std::cout << "Error: Los datos de la persona no pueden estar vacios.\n";
          break;
        }

        casilleros.insert(casillero_temporal);
        std::cout << "Casillero " << numero << " asignado correctamente a "
                  << casillero_temporal.persona.nombre << ".\n";
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

        // Para borrar basta un Casillero con el mismo numero (por operator==)
        if (casilleros.erase(Casillero{numero, {}}) > 0) {
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

void BuscarCasillero(const std::unordered_set<Casillero, CasilleroHash>& casilleros,
                     int numero) {
  // Se busca con un Casillero "llave" que solo tiene el numero
  auto iterador = casilleros.find(Casillero{numero, {}});

  if (iterador != casilleros.end()) {
    std::cout << "Casillero " << iterador->numero << " OCUPADO -> Nombre: "
              << iterador->persona.nombre
              << " - Identificacion: " << iterador->persona.identificacion
              << "\n";
  } else {
    std::cout << "El casillero " << numero << " esta disponible.\n";
  }
}

void MostrarCasilleros(const std::unordered_set<Casillero, CasilleroHash>& casilleros) {
  std::cout << "\n--- Casilleros Ocupados (std::unordered_set - Sin orden) ---\n";
  int contador = 1;

  std::for_each(casilleros.begin(), casilleros.end(),
                [&contador](const Casillero& casillero) {
                  std::cout << contador++ << ". Casillero " << casillero.numero
                            << " - Nombre: " << casillero.persona.nombre
                            << " - Identificacion: "
                            << casillero.persona.identificacion << "\n";
                });
}


#include <algorithm>
#include <iostream>
#include <set>
#include <string>

struct Contacto {
  std::string nombre;
  std::string telefono;
  std::string correo;

  // Sobrecarga de operador < para ordenar por nombre alfabéticamente
  bool operator<(const Contacto& otro) const {
    return nombre < otro.nombre;
  }
};

void SolicitarDatos(Contacto& contacto);
void MostrarAgenda(const std::set<Contacto>& agenda);
void BuscarContactoPorNombre(const std::set<Contacto>& agenda,
                             const std::string& nombre_buscar);

int main() {
  int opcion = 0;
  std::string nombre_buscar;
  Contacto contacto_temporal;
  std::set<Contacto> agenda_contactos;

  do {
    std::cout << "\n=== Agenda Telefonica (std::set) ===\n";
    std::cout << "1. Agregar contacto\n";
    std::cout << "2. Mostrar contactos ordenados alfabeticamente\n";
    std::cout << "3. Buscar contacto por nombre\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    switch (opcion) {
      case 1: {
        SolicitarDatos(contacto_temporal);
        const auto resultado = agenda_contactos.insert(contacto_temporal);
        if (resultado.second) {
          std::cout << "Contacto registrado correctamente en el conjunto.\n";
        } else {
          std::cout << "Aviso: El contacto \"" << contacto_temporal.nombre
                    << "\" ya existe en la agenda. No se permiten duplicados.\n";
        }
        break;
      }

      case 2:
        if (agenda_contactos.empty()) {
          std::cout << "La agenda esta vacia. Agregue contactos primero.\n";
        } else {
          MostrarAgenda(agenda_contactos);
        }
        break;

      case 3:
        if (agenda_contactos.empty()) {
          std::cout << "La agenda esta vacia. No se puede realizar la busqueda.\n";
        } else {
          std::cout << "Ingresa el nombre del contacto a buscar: ";
          std::cin >> nombre_buscar;
          BuscarContactoPorNombre(agenda_contactos, nombre_buscar);
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

void SolicitarDatos(Contacto& contacto) {
  std::cout << "Ingresar el nombre del contacto: ";
  std::cin >> contacto.nombre;

  std::cout << "Ingresar el numero de telefono: ";
  std::cin >> contacto.telefono;

  std::cout << "Ingresar el correo electronico: ";
  std::cin >> contacto.correo;
}

void MostrarAgenda(const std::set<Contacto>& agenda) {
  std::cout << "\n--- Agenda Telefonica (std::set - Red-Black Tree) ---\n";
  int contador = 1;

  std::for_each(agenda.begin(), agenda.end(), [&contador](const Contacto& contacto) {
    std::cout << contador++ << ". Nombre: " << contacto.nombre
              << " - Telefono: " << contacto.telefono
              << " - Correo: " << contacto.correo << "\n";
  });
}

void BuscarContactoPorNombre(const std::set<Contacto>& agenda,
                             const std::string& nombre_buscar) {
  Contacto clave{nombre_buscar, "", ""};
  auto iterador = agenda.find(clave);

  if (iterador != agenda.end()) {
    std::cout << "Contacto encontrado: " << iterador->nombre
              << " - Telefono: " << iterador->telefono
              << " - Correo: " << iterador->correo << "\n";
  } else {
    std::cout << "No se encontro ningun contacto con el nombre \""
              << nombre_buscar << "\".\n";
  }
}
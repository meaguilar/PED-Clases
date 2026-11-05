#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <string>

struct Contacto {
  std::string nombre;
  std::string telefono;
  std::string correo;

  // Ordena alfabéticamente por nombre (y por teléfono si tienen el mismo nombre)
  bool operator<(const Contacto& otro) const {
    if (nombre != otro.nombre) {
      return nombre < otro.nombre;
    }
    return telefono < otro.telefono;
  }
};

void SolicitarDatos(Contacto& contacto);
bool ExisteTelefono(const std::set<Contacto>& agenda, const std::string& telefono_buscar);
void MostrarAgenda(const std::set<Contacto>& agenda);
void BuscarContactoPorNombre(const std::set<Contacto>& agenda, const std::string& nombre_buscar);

int main() {
  int opcion = 0;
  std::string nombre_buscar;
  Contacto contacto_temporal;
  std::set<Contacto> agenda_contactos;

  do {
    std::cout << "\n=== Agenda Telefonica (std::set) ===\n";
    std::cout << "1. Agregar contacto\n";
    std::cout << "2. Mostrar contactos ordenados alfabeticamente por nombre\n";
    std::cout << "3. Buscar contacto por nombre\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    switch (opcion) {
      case 1:
        SolicitarDatos(contacto_temporal);
        if (ExisteTelefono(agenda_contactos, contacto_temporal.telefono)) {
          std::cout << "Aviso: El numero de telefono \""
                    << contacto_temporal.telefono
                    << "\" ya existe en la agenda. No se permiten duplicados.\n";
        } else {
          agenda_contactos.insert(contacto_temporal);
          std::cout << "Contacto registrado correctamente en el conjunto.\n";
        }
        break;

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

  std::cout << "Ingresar el numero de telefono (clave unica): ";
  std::cin >> contacto.telefono;

  std::cout << "Ingresar el correo electronico: ";
  std::cin >> contacto.correo;
}

bool ExisteTelefono(const std::set<Contacto>& agenda,
                    const std::string& telefono_buscar) {
  auto iterador = std::find_if(
      agenda.begin(), agenda.end(),
      [&telefono_buscar](const Contacto& contacto) {
        return contacto.telefono == telefono_buscar;
      });
  return iterador != agenda.end();
}

void MostrarAgenda(const std::set<Contacto>& agenda) {
  std::cout << "\n--- Agenda Telefonica (std::set - Orden Alfabetico por Nombre) ---\n";
  int contador = 1;

  std::for_each(agenda.begin(), agenda.end(),
                [&contador](const Contacto& contacto) {
                  std::cout << contador++ << ". Nombre: " << contacto.nombre
                            << " - Telefono: " << contacto.telefono
                            << " - Correo: " << contacto.correo << "\n";
                });
}

void BuscarContactoPorNombre(const std::set<Contacto>& agenda,
                             const std::string& nombre_buscar) {
  auto iterador = std::find_if(
      agenda.begin(), agenda.end(),
      [&nombre_buscar](const Contacto& contacto) {
        return contacto.nombre == nombre_buscar;
      });

  if (iterador != agenda.end()) {
    std::cout << "Contacto encontrado: Nombre: " << iterador->nombre
              << " - Telefono: " << iterador->telefono
              << " - Correo: " << iterador->correo << "\n";
  } else {
    std::cout << "No se encontro ningun contacto con el nombre \""
              << nombre_buscar << "\".\n";
  }
}

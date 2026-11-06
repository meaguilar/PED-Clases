
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>

struct Contacto {
  std::string nombre;
  std::string telefono;
  std::string correo;
};

void SolicitarDatos(Contacto& contacto);
void MostrarAgenda(const std::map<std::string, Contacto>& agenda);
void BuscarContactoPorNombre(
    const std::map<std::string, Contacto>& agenda,
    const std::string& nombre_buscar);

int main() {
  int opcion = 0;
  std::string nombre_buscar;
  Contacto contacto_temporal;

  std::map<std::string, Contacto> agenda_contactos;

  do {
    std::cout << "\n=== Agenda Telefonica (std::map) ===\n";
    std::cout << "1. Agregar contacto\n";
    std::cout << "2. Mostrar contactos ordenados por telefono\n";
    std::cout << "3. Buscar contacto por nombre\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    switch (opcion) {
      case 1: {
        SolicitarDatos(contacto_temporal);

        const auto resultado = agenda_contactos.insert(
            {contacto_temporal.telefono, contacto_temporal});

        if (resultado.second) {
          std::cout << "Contacto registrado correctamente en el mapa.\n";
        } else {
          std::cout << "Aviso: Ya existe un contacto registrado con el telefono \""
                    << contacto_temporal.telefono
                    << "\". No se permiten claves duplicadas.\n";
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

  std::cout << "Ingresar el numero de telefono (clave unica): ";
  std::cin >> contacto.telefono;

  std::cout << "Ingresar el correo electronico: ";
  std::cin >> contacto.correo;
}

void MostrarAgenda(const std::map<std::string, Contacto>& agenda) {
  std::cout << "\n--- Directorio de Contactos (std::map) ---\n";
  int contador = 1;

  std::for_each(
      agenda.begin(), agenda.end(),
      [&contador](const auto& entrada) {
        std::cout << contador++ << " - Nombre: " << entrada.second.nombre
                  << ". Telefono: "<< entrada.first         
                  << " - Correo: " << entrada.second.correo << "\n";
      });
}

void BuscarContactoPorNombre(
    const std::map<std::string, Contacto>& agenda,
    const std::string& nombre_buscar) {

  auto iterador = std::find_if(
      agenda.begin(), agenda.end(),
      [&nombre_buscar](const auto& entrada) {
        return entrada.second.nombre == nombre_buscar;
      });

  if (iterador != agenda.end()) {
    std::cout << "Contacto encontrado: Nombre: "
              << iterador->second.nombre
              << " - Telefono: " << iterador->first
              << " - Correo: " << iterador->second.correo << "\n";
    } else {
    std::cout << "No se encontro ningun contacto con el nombre \""
              << nombre_buscar << "\".\n";
  }
}

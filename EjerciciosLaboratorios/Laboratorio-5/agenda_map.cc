#include <algorithm>
#include <iostream>
#include <map>
#include <string>

// Representa los datos asociados al contacto (sin incluir la clave que es el nombre)
struct DetalleContacto {
  std::string telefono;
  std::string correo;
};

void SolicitarDatos(std::string& nombre, DetalleContacto& detalle);
void MostrarAgenda(const std::map<std::string, DetalleContacto>& agenda);
void BuscarContactoPorNombre(
    const std::map<std::string, DetalleContacto>& agenda,
    const std::string& nombre_buscar);

int main() {
  int opcion = 0;
  std::string nombre_buscar;
  std::string nuevo_nombre;
  DetalleContacto detalle_temporal;
  std::map<std::string, DetalleContacto> agenda_contactos;

  do {
    std::cout << "\n=== Agenda Telefonica (std::map) ===\n";
    std::cout << "1. Agregar contacto\n";
    std::cout << "2. Mostrar contactos ordenados por nombre\n";
    std::cout << "3. Buscar contacto por nombre (O(log n))\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    switch (opcion) {
      case 1: {
        SolicitarDatos(nuevo_nombre, detalle_temporal);
        const auto resultado =
            agenda_contactos.insert({nuevo_nombre, detalle_temporal});

        if (resultado.second) {
          std::cout << "Contacto registrado correctamente en el mapa.\n";
        } else {
          std::cout << "Aviso: Ya existe un contacto registrado con el nombre \""
                    << nuevo_nombre << "\". No se permiten claves duplicadas.\n";
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

void SolicitarDatos(std::string& nombre, DetalleContacto& detalle) {
  std::cout << "Ingresar el nombre del contacto (clave): ";
  std::cin >> nombre;

  std::cout << "Ingresar el numero de telefono: ";
  std::cin >> detalle.telefono;

  std::cout << "Ingresar el correo electronico: ";
  std::cin >> detalle.correo;
}

void MostrarAgenda(const std::map<std::string, DetalleContacto>& agenda) {
  std::cout << "\n--- Directorio de Contactos (std::map - Clave/Valor) ---\n";
  int contador = 1;

  // Función lambda para recorrer e imprimir cada entrada del mapa
  std::for_each(agenda.begin(), agenda.end(),
                [&contador](const auto& entrada) {
                  std::cout << contador++ << ". Nombre: " << entrada.first
                            << " - Telefono: " << entrada.second.telefono
                            << " - Correo: " << entrada.second.correo << "\n";
                });
}

void BuscarContactoPorNombre(
    const std::map<std::string, DetalleContacto>& agenda,
    const std::string& nombre_buscar) {
  auto iterador = agenda.find(nombre_buscar);

  if (iterador != agenda.end()) {
    std::cout << "Contacto encontrado: " << iterador->first
              << " - Telefono: " << iterador->second.telefono
              << " - Correo: " << iterador->second.correo << "\n";
  } else {
    std::cout << "No se encontro ningun contacto con el nombre \""
              << nombre_buscar << "\".\n";
  }
}

#include <iostream>
#include <string>

struct Contacto {
  std::string nombre;
  std::string telefono;
  std::string correo;
};

// Representa un nodo en el árbol binario de búsqueda
struct NodoContacto {
  Contacto contacto;
  NodoContacto* izquierdo;
  NodoContacto* derecho;

  explicit NodoContacto(const Contacto& nuevo_contacto)
      : contacto(nuevo_contacto), izquierdo(nullptr), derecho(nullptr) {}
};

void SolicitarDatos(Contacto& contacto);
NodoContacto* InsertarNodo(NodoContacto* raiz, const Contacto& nuevo_contacto, bool& fue_insertado);
NodoContacto* BuscarNodo(NodoContacto* raiz, const std::string& nombre_buscar);
void MostrarAgenda(NodoContacto* raiz);
void BuscarContactoPorNombre(NodoContacto* raiz, const std::string& nombre_buscar);
void LiberarArbol(NodoContacto*& raiz);

int main() {
  int opcion = 0;
  std::string nombre_buscar;
  Contacto contacto_temporal;
  NodoContacto* raiz = nullptr;

  do {
    std::cout << "\n=== Agenda Telefonica (ABB Manual) ===\n";
    std::cout << "1. Agregar contacto\n";
    std::cout << "2. Mostrar contactos ordenados (Inorden)\n";
    std::cout << "3. Buscar contacto por nombre\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    switch (opcion) {
      case 1: {
        SolicitarDatos(contacto_temporal);
        bool fue_insertado = false;
        raiz = InsertarNodo(raiz, contacto_temporal, fue_insertado);
        if (fue_insertado) {
          std::cout << "Contacto registrado correctamente en el arbol.\n";
        } else {
          std::cout << "Aviso: Ya existe un contacto con el nombre \""
                    << contacto_temporal.nombre << "\". No se permiten duplicados.\n";
        }
        break;
      }

      case 2:
        if (raiz == nullptr) {
          std::cout << "La agenda esta vacia. Agregue contactos primero.\n";
        } else {
          MostrarAgenda(raiz);
        }
        break;

      case 3:
        if (raiz == nullptr) {
          std::cout << "La agenda esta vacia. No se puede realizar la busqueda.\n";
        } else {
          std::cout << "Ingresa el nombre del contacto a buscar: ";
          std::cin >> nombre_buscar;
          BuscarContactoPorNombre(raiz, nombre_buscar);
        }
        break;

      case 0:
        std::cout << "Saliendo del programa y liberando memoria...\n";
        LiberarArbol(raiz);
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

NodoContacto* InsertarNodo(NodoContacto* raiz, const Contacto& nuevo_contacto,
                           bool& fue_insertado) {
  if (raiz == nullptr) {
    fue_insertado = true;
    return new NodoContacto(nuevo_contacto);
  }

  if (nuevo_contacto.nombre < raiz->contacto.nombre) {
    raiz->izquierdo = InsertarNodo(raiz->izquierdo, nuevo_contacto, fue_insertado);
  } else if (nuevo_contacto.nombre > raiz->contacto.nombre) {
    raiz->derecho = InsertarNodo(raiz->derecho, nuevo_contacto, fue_insertado);
  } else {
    fue_insertado = false;
  }

  return raiz;
}

NodoContacto* BuscarNodo(NodoContacto* raiz, const std::string& nombre_buscar) {
  if (raiz == nullptr || raiz->contacto.nombre == nombre_buscar) {
    return raiz;
  }

  if (nombre_buscar < raiz->contacto.nombre) {
    return BuscarNodo(raiz->izquierdo, nombre_buscar);
  }

  return BuscarNodo(raiz->derecho, nombre_buscar);
}

template <typename Accion>
void RecorridoInorden(NodoContacto* raiz, Accion accion) {
  if (raiz != nullptr) {
    RecorridoInorden(raiz->izquierdo, accion);
    accion(raiz->contacto);
    RecorridoInorden(raiz->derecho, accion);
  }
}

void MostrarAgenda(NodoContacto* raiz) {
  std::cout << "\n--- Contactos Registrados (Orden Alfabetico por ABB) ---\n";
  int contador = 1;

  auto imprimir_contacto = [&contador](const Contacto& c) {
    std::cout << contador++ << ". Nombre: " << c.nombre
              << " - Telefono: " << c.telefono
              << " - Correo: " << c.correo << "\n";
  };

  RecorridoInorden(raiz, imprimir_contacto);
}

void BuscarContactoPorNombre(NodoContacto* raiz,
                             const std::string& nombre_buscar) {
  NodoContacto* resultado = BuscarNodo(raiz, nombre_buscar);

  if (resultado != nullptr) {
    std::cout << "Contacto encontrado: " << resultado->contacto.nombre
              << " - Telefono: " << resultado->contacto.telefono
              << " - Correo: " << resultado->contacto.correo << "\n";
  } else {
    std::cout << "No se encontro ningun contacto con el nombre \""
              << nombre_buscar << "\".\n";
  }
}

void LiberarArbol(NodoContacto*& raiz) {
  if (raiz != nullptr) {
    LiberarArbol(raiz->izquierdo);
    LiberarArbol(raiz->derecho);
    delete raiz;
    raiz = nullptr;
  }
}
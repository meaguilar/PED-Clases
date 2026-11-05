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
};

void SolicitarDatos(Contacto& contacto);
NodoContacto* CrearNodo(const Contacto& nuevo_contacto);
NodoContacto* InsertarNodo(NodoContacto* raiz, const Contacto& nuevo_contacto, bool& fue_insertado);
void RecorridoInorden(NodoContacto* raiz, int& contador);
void MostrarAgenda(NodoContacto* raiz);
bool BuscarContactoPorNombre(NodoContacto* raiz, const std::string& nombre_buscar);
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
          std::cout << "Aviso: Ya existe un contacto con el numero \""
                    << contacto_temporal.telefono
                    << "\". No se permiten numeros duplicados.\n";
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
          if (!BuscarContactoPorNombre(raiz, nombre_buscar)) {
            std::cout << "No se encontro ningun contacto con el nombre \""
                      << nombre_buscar << "\".\n";
          }
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

NodoContacto* CrearNodo(const Contacto& nuevo_contacto) {
  NodoContacto* nuevo_nodo = new NodoContacto;
  nuevo_nodo->contacto = nuevo_contacto;
  nuevo_nodo->izquierdo = nullptr;
  nuevo_nodo->derecho = nullptr;
  return nuevo_nodo;
}

NodoContacto* InsertarNodo(NodoContacto* raiz, const Contacto& nuevo_contacto,
                           bool& fue_insertado) {
  if (raiz == nullptr) {
    fue_insertado = true;
    return CrearNodo(nuevo_contacto);
  }

  if (nuevo_contacto.telefono < raiz->contacto.telefono) {
    raiz->izquierdo =
        InsertarNodo(raiz->izquierdo, nuevo_contacto, fue_insertado);
  } else if (nuevo_contacto.telefono > raiz->contacto.telefono) {
    raiz->derecho = InsertarNodo(raiz->derecho, nuevo_contacto, fue_insertado);
  } else {
    fue_insertado = false;
  }

  return raiz;
}

void RecorridoInorden(NodoContacto* raiz, int& contador) {
    if (raiz != nullptr) {
        RecorridoInorden(raiz->izquierdo, contador);
        
        auto imprimir_contacto = [&contador](const Contacto& c) {
        std::cout << contador++ << ". Nombre: " << c.nombre
                  << " - Telefono: " << c.telefono
                  << " - Correo: " << c.correo << "\n";
    };
    imprimir_contacto(raiz->contacto);

    RecorridoInorden(raiz->derecho, contador);
  }
}

void MostrarAgenda(NodoContacto* raiz) {
  std::cout << "\n--- Contactos Registrados (Ordenados por Telefono en ABB) ---\n";
  int contador = 1;
  RecorridoInorden(raiz, contador);
}

bool BuscarContactoPorNombre(NodoContacto* raiz,
                             const std::string& nombre_buscar) {
  if (raiz == nullptr) {
    return false;
  }

  auto coincide_nombre = [&nombre_buscar](const Contacto& c) {
    return c.nombre == nombre_buscar;
  };

  if (coincide_nombre(raiz->contacto)) {
    std::cout << "Contacto encontrado: Nombre: " << raiz->contacto.nombre
              << " - Telefono: " << raiz->contacto.telefono
              << " - Correo: " << raiz->contacto.correo << "\n";
    return true;
  }

  return BuscarContactoPorNombre(raiz->izquierdo, nombre_buscar) ||
         BuscarContactoPorNombre(raiz->derecho, nombre_buscar);
}

void LiberarArbol(NodoContacto*& raiz) {
  if (raiz != nullptr) {
    LiberarArbol(raiz->izquierdo);
    LiberarArbol(raiz->derecho);
    delete raiz;
    raiz = nullptr;
  }
}

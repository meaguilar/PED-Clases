#include <iostream>
#include <string>

// Cantidad de buckets (posiciones) que tiene la tabla hash
const int kTamanoTabla = 10;

struct Persona {
  std::string nombre;
  std::string identificacion;
};

struct Casillero {
  int numero;
  Persona persona;
};

struct NodoCasillero {
  Casillero casillero;
  NodoCasillero* siguiente;
};

bool SolicitarDatosPersona(Persona& persona);
int FuncionHash(int numero);
void InicializarTabla(NodoCasillero* tabla[]);
bool EstaVaciaTabla(NodoCasillero* tabla[]);
NodoCasillero* BuscarCasillero(NodoCasillero* tabla[], int numero);
bool AsignarCasillero(NodoCasillero* tabla[], const Casillero& nuevo_casillero);
bool LiberarCasillero(NodoCasillero* tabla[], int numero);
void MostrarCasilleros(NodoCasillero* tabla[]);
void LiberarTabla(NodoCasillero* tabla[]);

int main() {
  int opcion = 0;
  int numero = 0;
  NodoCasillero* tabla[kTamanoTabla];
  InicializarTabla(tabla);

  do {
    std::cout << "\n=== Sistema de Casilleros Inteligentes ===\n";
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

        if (BuscarCasillero(tabla, numero) != nullptr) {
          std::cout << "Aviso: El casillero " << numero
                    << " ya esta ocupado. No se permiten duplicados.\n";
          break;
        }

        Casillero nuevo_casillero;
        nuevo_casillero.numero = numero;
        if (!SolicitarDatosPersona(nuevo_casillero.persona)) {
          std::cout << "Error: Los datos de la persona no pueden estar vacios.\n";
          break;
        }

        AsignarCasillero(tabla, nuevo_casillero);
        std::cout << "Casillero " << numero << " asignado correctamente a "
                  << nuevo_casillero.persona.nombre << " (bucket "
                  << FuncionHash(numero) << ").\n";
        break;
      }

      case 2: {
        if (EstaVaciaTabla(tabla)) {
          std::cout << "No hay casilleros ocupados. Todos estan disponibles.\n";
          break;
        }

        std::cout << "Ingrese el numero del casillero a buscar: ";
        std::cin >> numero;
        if (numero <= 0) {
          std::cout << "Error: El numero del casillero debe ser un entero positivo.\n";
          break;
        }

        NodoCasillero* encontrado = BuscarCasillero(tabla, numero);
        if (encontrado != nullptr) {
          std::cout << "Casillero " << numero << " OCUPADO -> Nombre: "
                    << encontrado->casillero.persona.nombre
                    << " - Identificacion: "
                    << encontrado->casillero.persona.identificacion << "\n";
        } else {
          std::cout << "El casillero " << numero << " esta disponible.\n";
        }
        break;
      }

      case 3:
        if (EstaVaciaTabla(tabla)) {
          std::cout << "No hay casilleros ocupados para liberar.\n";
          break;
        }

        std::cout << "Ingrese el numero del casillero a liberar: ";
        std::cin >> numero;
        if (numero <= 0) {
          std::cout << "Error: El numero del casillero debe ser un entero positivo.\n";
          break;
        }

        if (LiberarCasillero(tabla, numero)) {
          std::cout << "Casillero " << numero << " liberado correctamente.\n";
        } else {
          std::cout << "Aviso: El casillero " << numero
                    << " no esta ocupado. No se puede liberar.\n";
        }
        break;

      case 4:
        if (EstaVaciaTabla(tabla)) {
          std::cout << "No hay casilleros ocupados.\n";
        } else {
          MostrarCasilleros(tabla);
        }
        break;

      case 0:
        std::cout << "Saliendo del programa...\n";
        LiberarTabla(tabla);
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

// Funcion hash: el residuo de la division indica el bucket del casillero
int FuncionHash(int numero) {
  return numero % kTamanoTabla;
}

void InicializarTabla(NodoCasillero* tabla[]) {
  for (int i = 0; i < kTamanoTabla; i++) {
    tabla[i] = nullptr;
  }
}

bool EstaVaciaTabla(NodoCasillero* tabla[]) {
  for (int i = 0; i < kTamanoTabla; i++) {
    if (tabla[i] != nullptr) {
      return false;
    }
  }
  return true;
}

// Solo recorre la lista del bucket que indica la funcion hash
NodoCasillero* BuscarCasillero(NodoCasillero* tabla[], int numero) {
  NodoCasillero* actual = tabla[FuncionHash(numero)];
  while (actual != nullptr) {
    if (actual->casillero.numero == numero) {
      return actual;
    }
    actual = actual->siguiente;
  }
  return nullptr;
}

// Inserta al inicio de la lista del bucket; si hay colision, se encadena
bool AsignarCasillero(NodoCasillero* tabla[], const Casillero& nuevo_casillero) {
  if (BuscarCasillero(tabla, nuevo_casillero.numero) != nullptr) {
    return false;
  }

  int indice = FuncionHash(nuevo_casillero.numero);
  NodoCasillero* nuevo_nodo = new NodoCasillero;
  nuevo_nodo->casillero = nuevo_casillero;
  nuevo_nodo->siguiente = tabla[indice];
  tabla[indice] = nuevo_nodo;
  return true;
}

bool LiberarCasillero(NodoCasillero* tabla[], int numero) {
  int indice = FuncionHash(numero);
  NodoCasillero* actual = tabla[indice];
  NodoCasillero* anterior = nullptr;

  while (actual != nullptr) {
    if (actual->casillero.numero == numero) {
      if (anterior == nullptr) {
        tabla[indice] = actual->siguiente;
      } else {
        anterior->siguiente = actual->siguiente;
      }
      delete actual;
      return true;
    }
    anterior = actual;
    actual = actual->siguiente;
  }
  return false;
}

void MostrarCasilleros(NodoCasillero* tabla[]) {
  std::cout << "\n--- Casilleros Ocupados ---\n";
  for (int i = 0; i < kTamanoTabla; i++) {
    NodoCasillero* actual = tabla[i];
    if (actual == nullptr) {
      continue;
    }

    std::cout << "Bucket [" << i << "]:\n";
    while (actual != nullptr) {
      std::cout << "   Casillero " << actual->casillero.numero
                << " - Nombre: " << actual->casillero.persona.nombre
                << " - Identificacion: "
                << actual->casillero.persona.identificacion << "\n";
      actual = actual->siguiente;
    }
  }
}

void LiberarTabla(NodoCasillero* tabla[]) {
  for (int i = 0; i < kTamanoTabla; i++) {
    NodoCasillero* actual = tabla[i];
    while (actual != nullptr) {
      NodoCasillero* siguiente = actual->siguiente;
      delete actual;
      actual = siguiente;
    }
    tabla[i] = nullptr;
  }
}


#include <iostream>
#include <stack>
#include <string>

// Almacena la informacion de una pagina visitada.
struct Pagina {
    std::string url;
    int numero_visitas;
    std::string fecha_visita;
};
//Declarando las funciones 
bool LlenarDatosPagina(Pagina& pagina);
void AgregarPagina(std::stack<Pagina>& historial, const Pagina& pagina);
void MostrarHistorial(std::stack<Pagina> historial);
void RetrocederPagina(std::stack<Pagina>& historial);

int main() {
    std::stack<Pagina> historial;
    int opcion;

    do {
        std::cout << "\n=== Historial de navegacion ===\n";
        std::cout << "1. Agregar pagina\n";
        std::cout << "2. Mostrar historial\n";
        std::cout << "3. Retroceder pagina\n";
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
            case 1:{
                Pagina nueva;
                if (LlenarDatosPagina(nueva)) {
                    AgregarPagina(historial, nueva);
                }
                break;
            }
            case 2:
                MostrarHistorial(historial);
                break;

            case 3:
                RetrocederPagina(historial);
                break;

            case 0:
                std::cout << "Cerrando el navegador.\n";
                break;

            default:
                std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}

bool LlenarDatosPagina(Pagina& pagina) {
    std::cout << "Ingrese la URL o nombre de la pagina: ";
    std::getline(std::cin, pagina.url);

    std::cout << "Ingrese el numero de visitas: ";
    if (!(std::cin >> pagina.numero_visitas) || pagina.numero_visitas < 1) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "El numero de visitas debe ser positivo.\n";
        return false;
    }
    std::cin.ignore(1000, '\n');

    std::cout << "Ingrese la fecha de visita: ";
    std::getline(std::cin, pagina.fecha_visita);

    return true;
}
// Registra una nueva pagina en la cima de la pila.
void AgregarPagina(std::stack<Pagina>& historial, const Pagina& pagina) {
    historial.push(pagina);

    std::cout << "Pagina registrada correctamente.\n";
}

// Muestra el historial sin modificar la pila original.
void MostrarHistorial(std::stack<Pagina> historial) {
    if (historial.empty()) {
        std::cout << "El historial esta vacio.\n";
        return;
    }

    std::cout << "\n--- Historial de navegacion ---\n";

    int posicion = 1;

    while (!historial.empty()) {
        Pagina actual = historial.top();

        std::cout << "\nPagina #" << posicion << "\n";
        std::cout << "URL: " << actual.url << "\n";
        std::cout << "Numero de visitas: "
                  << actual.numero_visitas << "\n";
        std::cout << "Fecha de visita: "
                  << actual.fecha_visita << "\n";

        historial.pop();
        posicion++;
    }
}

// Elimina la pagina mas reciente del historial.
void RetrocederPagina(std::stack<Pagina>& historial) {
    if (historial.empty()) {
        std::cout << "No hay paginas para retroceder.\n";
        return;
    }

    std::cout << "Retrocediste desde "
              << historial.top().url << "\n";

    historial.pop();
}

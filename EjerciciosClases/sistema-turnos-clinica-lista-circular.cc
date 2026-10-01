#include <iostream>

// Desde C++20 activa funcionalidades de calendario
#include <chrono>

struct Paciente
{
    std::string nombre_completo;
    int anio_nac;
    unsigned mes_nac;
    unsigned dia_nac;
    int edad;
    float peso;
    float estatura;
    std::string tipo_sangre;
};

struct Nodo
{
    Paciente paciente;
    Nodo *siguiente;
};

// Declaración de funciones usando referencias (*&)
void InsertarFinal(Nodo *&lista, Paciente paciente);
struct Paciente SolicitarDatosPaciente(Paciente &paciente);
void EliminarInicio(struct Nodo *&lista);
void Imprimir(struct Nodo *lista);
int CalcularEdad(int anio, unsigned mes, unsigned dia);

int main()
{
    char continuar;
    Nodo *lista = nullptr;
    Paciente paciente;

    do
    {
        SolicitarDatosPaciente(paciente);
        InsertarFinal(lista, paciente);

        std::cout << "¿Desea ingresar otro paciente? (s/n): ";
        std::cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    std::cout << "Primer paciente de la lista circular" << lista->paciente.nombre_completo << "Dir. memoria " << lista << "\n";
    std::cout << "Segundo paciente de la lista circular" << lista->siguiente->paciente.nombre_completo << "Dir. memoria" << lista->siguiente << "\n";

    std::cout << "\n....Imprimiendo lista de pacientes ...... \n";
    Imprimir(lista);

    std::cout << "\n....Actualizando lista...... \n";
    EliminarInicio(lista);
    Imprimir(lista);

    return 0;
}

struct Paciente SolicitarDatosPaciente(Paciente &paciente)
{

    std::cout << "Ingresa el nombre completo: ";
    std::cin >> paciente.nombre_completo;

    std::cout << "\nFecha de nacimiento (2000 09 01)\n";

    std::cout << "Ingresa el anio (2000): ";
    std::cin >> paciente.anio_nac;

    std::cout << "Ingresa el mes (09): ";
    std::cin >> paciente.mes_nac;

    std::cout << "Ingresa el dia (01): ";
    std::cin >> paciente.dia_nac;

    // Calcular edad
    paciente.edad = CalcularEdad(paciente.anio_nac, paciente.mes_nac, paciente.dia_nac);

    std::cout << "Ingresa el peso en Lbs: ";
    std::cin >> paciente.peso;

    std::cout << "Ingresa al altura en Mts: ";
    std::cin >> paciente.estatura;

    std::cout << "Ingresa el tipo de sangre: ";
    std::cin >> paciente.tipo_sangre;

    return paciente;
}

// Insertar al final de la lista circular
void InsertarFinal(Nodo *&lista, Paciente paciente)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->paciente = paciente;

    if (lista == nullptr)
    {
        lista = nuevo_nodo;
        // circularidad
        lista->siguiente = lista;
    }

    Nodo *temporal = lista;
    while (temporal->siguiente != lista)
    {
        temporal = temporal->siguiente;
    }

    temporal->siguiente = nuevo_nodo;
    // Cierra el círculo apuntando a la cabeza
    nuevo_nodo->siguiente = lista;
}

// Eliminar el primer nodo
void EliminarInicio(Nodo *&lista)
{
    if (lista == nullptr)
    {
        std::cout << "Lista vacia\n";
        return;
    }

    // Si solo hay un elemento en la lista circular
    if (lista->siguiente == lista)
    {
        delete lista;
        lista = nullptr;
        return;
    }

    // Buscamos el último nodo para actualizar su enlace
    Nodo *temporal = lista;
    while (temporal->siguiente != lista)
    {
        temporal = temporal->siguiente;
    }

    Nodo *a_borrar = lista;
    lista = lista->siguiente;
    // El último nodo ahora apunta a la nueva cabeza
    temporal->siguiente = lista;

    delete a_borrar;
}

// Imprimir la lista circular
void Imprimir(Nodo *lista)
{
    if (lista == nullptr)
    {
        std::cout << "Lista vacia\n";
        return;
    }

    Nodo *temporal = lista;
    do
    {
        std::cout << "Paciente: " << temporal->paciente.nombre_completo
                  << " | Direccion: " << temporal
                  << " | Dir siguiente: " << temporal->siguiente << "\n";
        temporal = temporal->siguiente;
    } while (temporal != lista);
}

int CalcularEdad(int anio, unsigned mes, unsigned dia)
{
    // Obtener fecha actual
    auto hoy =
        std::chrono::floor<std::chrono::days>(
            std::chrono::system_clock::now());

    // Obtener año, mes y dia actual
    std::chrono::year_month_day fechaActual{hoy};

    int edad =
        int(fechaActual.year()) - anio;

    // Verificar si todavía no ha cumplido años
    if (unsigned(fechaActual.month()) < mes || (unsigned(fechaActual.month()) == mes && unsigned(fechaActual.day()) < dia))
    {
        --edad;
    }

    return edad;
}
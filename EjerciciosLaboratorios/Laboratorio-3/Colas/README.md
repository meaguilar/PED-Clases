
## Montaña rusa – Cola

Una montaña rusa necesita organizar a las personas que esperan para subir al juego. Las personas deben subir respetando el mismo orden en que llegaron.

Además, cada persona debe recibir automáticamente un número de asiento consecutivo al ingresar a la cola.

### Estructura de datos

El sistema utilizará una **cola (`std::queue`)** y una estructura para almacenar la información de cada pasajero.

**Struct Persona:** almacena los datos de cada persona:

-   `nombre` (string): nombre de la persona.
    
-   `asiento` (int): número de asiento asignado automáticamente.
    
-   `categoria` (string): categoría del pasajero, por ejemplo, adulto o niño.
    

La cola debe mantener el orden de llegada de las personas, de manera que la primera persona en ingresar sea la primera en subir a la montaña rusa.

### Funciones implementadas

1.  `agregarPersona()` → solicita los datos de una persona, asigna un número de asiento y la agrega al final de la cola.
    
2.  `mostrarCola()` → muestra las personas que están esperando, respetando el orden de llegada sin modificar la cola.
    
3.  `iniciarViaje()` → permite que hasta cinco personas suban a la montaña rusa y elimina de la cola a las personas que subieron.
    

### Asignación automática de asientos

El número de asiento debe asignarse automáticamente cada vez que una persona ingresa a la cola.
Los números de asiento deben ser consecutivos y no deben repetirse durante la ejecución del programa.

### Operaciones de la cola

Las operaciones principales que se deben practicar son:

-   **Agregar (`push`)** → coloca una nueva persona al final de la cola.
    
-   **Consultar (`front`)** → permite acceder a la primera persona que espera.
    
-   **Eliminar (`pop`)** → retira a la primera persona de la cola.
    
-   **Verificar (`empty`)** → permite comprobar si existen personas esperando.
    

Al mostrar la cola, se debe tener cuidado de **no eliminar las personas de la cola original**. Se puede utilizar una copia de la cola para realizar el recorrido.

### Estructura del menú

```text
=== Sistema de Montaña Rusa ===
1. Agregar persona
2. Mostrar cola
3. Iniciar viaje
0. Salir

```

### Validaciones

El programa debe verificar que:

-   No se intente iniciar un viaje cuando la cola está vacía.
    
-   No se intente consultar el primer elemento cuando la cola está vacía.
    
-   Si existen menos de cinco personas, solo suban las personas disponibles.
    
-   Los números de asiento se asignen automáticamente y no se repitan durante la ejecución.
    
-   Mostrar la cola no elimine los elementos de la cola original.
    

> 💡 El menú es opcional y sirve para probar de forma interactiva cómo cambia la cola después de cada operación. El objetivo principal es comprender el comportamiento **FIFO (First In, First Out)** y las operaciones básicas de una cola.

----------


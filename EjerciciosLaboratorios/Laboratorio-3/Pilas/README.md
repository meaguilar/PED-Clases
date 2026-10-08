
##  Historial de navegación web – Pila

Un navegador web necesita mantener un historial de las páginas visitadas. Las páginas más recientes deben aparecer primero y, al retroceder, debe eliminarse la página que fue visitada más recientemente.

El sistema debe permitir registrar páginas, consultar el historial y retroceder en las páginas visitadas.

### Estructura de datos

El sistema utilizará una **pila (`std::stack`)** y una estructura para almacenar la información de cada página.

**Struct Pagina:** almacena los datos de cada página:

-   `url` (string): dirección o nombre de la página visitada.
    
-   `visitas` (int): cantidad de veces que se ha visitado la página.
    
-   `fecha` (string): fecha en que se registró la visita.
    

La pila debe mantener las páginas de acuerdo con el orden en que fueron registradas, de manera que la última página agregada sea la primera en ser consultada o eliminada.

### Funciones implementadas

1.  `agregarPagina()` → solicita los datos de una página y la agrega a la pila.
    
2.  `mostrarHistorial()` → muestra las páginas desde la más reciente hasta la más antigua sin modificar la pila.
    
3.  `retrocederPagina()` → elimina la página más reciente y muestra los datos de la página eliminada.
    
4.  `liberarHistorial()` → vacía la pila antes de finalizar el programa, si se considera necesario.
    

### Operaciones de la pila

Las operaciones principales que se deben practicar son:

-   **Agregar (`push`)** → coloca una nueva página en la parte superior de la pila.
    
-   **Consultar (`top`)** → permite acceder a la página más reciente.
    
-   **Eliminar (`pop`)** → elimina la página más reciente.
    
-   **Verificar (`empty`)** → permite comprobar si la pila contiene elementos.
    

Al mostrar el historial, se debe tener cuidado de **no perder la información almacenada**. Si se utiliza una copia de la pila para recorrer sus elementos, las operaciones de eliminación se realizan sobre la copia y no sobre el historial original.

### Estructura del menú

```text
=== Historial de Navegación ===
1. Agregar página
2. Mostrar historial
3. Retroceder página
0. Salir

```

### Validaciones

El programa debe verificar que:

-   No se intente retroceder cuando la pila está vacía.
    
-   No se intente consultar la página superior cuando la pila está vacía.
    
-   Al mostrar el historial, la pila original conserve todos sus elementos.
    

> 💡 El menú es opcional y sirve para probar de forma interactiva cómo cambia la pila después de cada operación. El objetivo principal es comprender el comportamiento **LIFO (Last In, First Out)** y las operaciones básicas de una pila.



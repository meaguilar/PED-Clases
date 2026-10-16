## Registro y Búsqueda de Estudiantes – Lista (`std::list`) y Algoritmos STL

  

Una institución académica necesita llevar un registro dinámico de sus estudiantes para organizarlos por edad y realizar consultas rápidas tanto por nombre como por edad.

  

El sistema debe permitir registrar múltiples estudiantes, ordenar automáticamente la colección de menor a mayor edad, mostrar el listado ordenado y ejecutar búsquedas lineales (todas las coincidencias por nombre) y binarias (verificación por edad) utilizando las librerías `<list>`, `<iterator>` y `<algorithm>`.

  

### Estructura de datos

  

El sistema utilizará una **lista doblemente enlazada (`std::list`)** junto con iteradores (`<iterator>`) y algoritmos de la librería estándar (`<algorithm>`), además de una estructura para almacenar la información de cada estudiante.

  

**Struct Estudiante:** almacena los datos de cada estudiante:

  

-  `nombre` (string): nombre del estudiante registrado.

-  `edad` (int): edad del estudiante en años.

  

La lista almacena los estudiantes conforme se registran y posteriormente se ordena de forma ascendente por edad mediante su método propio `sort()`, dejando los datos preparados tanto para su visualización como para la búsqueda binaria.

  

### Funciones implementadas

  

1.  `SolicitarDatos(Estudiante &e)` → solicita al usuario el nombre y la edad del estudiante, guardando los datos directamente por referencia.

2.  `CompararEdades(const Estudiante &a, const Estudiante &b)` → función auxiliar booleana que compara dos estructuras `Estudiante` para ordenarlas de menor a mayor edad.

3.  `Imprimir(std::list<Estudiante> lista)` → muestra todos los estudiantes registrados recorriendo una copia de la lista sin perder los datos originales.

4.  `BuscarEstudiantePorNombre(std::list<Estudiante> lista, std::string nombre_buscar)` → utiliza un iterador (`std::list<Estudiante>::iterator`) y `std::find_if` con una función anónima (*lambda*) dentro de un ciclo `while` para encontrar y mostrar todos los estudiantes que coincidan con el nombre buscado.

5.  `BuscarEstudiantePorEdadBinaria(std::list<Estudiante> lista, int edad_buscar)` → utiliza `std::binary_search` con una función anónima (*lambda*) sobre la lista previamente ordenada para verificar si existe al menos un estudiante con la edad indicada.

  

### Operaciones de la lista y algoritmos STL

  

Las operaciones principales que se practican en este ejercicio son:

  

-  **Agregar (`push_front`)** → inserta un nuevo estudiante al inicio de la lista.

-  **Consultar (`front`)** → permite acceder al primer estudiante disponible en el frente de la lista.

-  **Eliminar (`pop_front`)** → retira el primer elemento de la lista (utilizado sobre la copia al imprimir).

-  **Verificar (`empty`)** → comprueba si la lista contiene elementos antes de mostrar, ordenar o buscar.

-  **Ordenar (`lista.sort`)** → ordena los nodos de la lista en $O(n \log n)$ utilizando la función `CompararEdades`.

-  **Búsqueda lineal con predicado (`std::find_if`)** → recorre secuencialmente el rango `[resultado_it, lista.end())` en $O(n)$ evaluando una función anónima (*lambda*) para localizar cada coincidencia por nombre.

-  **Búsqueda binaria (`std::binary_search`)** → comprueba en la lista ordenada si existe un registro con la edad buscada mediante comparaciones logarítmicas $O(\log n)$.

  

Al imprimir los elementos con `Imprimir()`, la lista se pasa **por valor (copia)** para que las llamadas a `pop_front()` consuman únicamente la copia temporal y **no se pierda la información almacenada** en `lista_estudiantes` antes de realizar las búsquedas.

  

### Estructura del menú

  
```text

=== Registro de Estudiantes ===
1. Agregar estudiante
2. Ordenar y mostrar estudiantes
3. Buscar estudiante por nombre (Lineal - find_if)
4. Verificar edad de estudiante (Binaria - binary_search)
0. Salir
```

  

### Validaciones

  

El programa debe verificar que:

  

- No se intente mostrar ni ordenar la lista cuando está vacía.
- No se intente realizar una búsqueda lineal o binaria cuando la lista está vacía.
- Al mostrar la lista en `Imprimir()`, la lista original conserve todos sus elementos.
- En `BuscarEstudiantePorNombre()`, el iterador `resultado_it` se incremente (`resultado_it++`) **únicamente dentro del bloque `if (resultado_it != lista.end())`**, evitando incrementar `lista.end()` y previniendo un ciclo infinito al terminar el recorrido.
- La lista se ordene previamente por edad antes de invocar `std::binary_search`.

  

> 💡 El menú es opcional y sirve para probar de forma interactiva cómo cambia la lista después de cada operación. El objetivo principal es comprender el uso de `std::list` junto con iteradores (`<iterator>`), algoritmos de la STL (`<algorithm>`) y funciones anónimas (*lambdas*).

  

---

  

**En este ejercicio se utiliza `std::list` junto con `<iterator>` y `<algorithm>` para almacenar estructuras `Estudiante`, ordenarlas eficientemente en $O(n \log n)$ y realizar tanto búsquedas lineales de múltiples coincidencias como búsquedas binarias sobre datos ordenados.**

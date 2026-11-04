## Enunciado del Problema

Una aplicación de agenda telefónica necesita desarrollar un programa para organizar y consultar información de contactos. Cada contacto contiene un **nombre**, un **número de teléfono** y un **correo electrónico**.

Se requiere implementar tres soluciones diferentes en C++ utilizando un `struct` para representar los datos de cada contacto:

1. **Solución manual:** Implementar un árbol binario de búsqueda (ABB) desde cero para almacenar, ordenar y buscar contactos por nombre, utilizando nodos y punteros, sin emplear contenedores asociativos de la STL como `set` o `map`.
2. **Solución con set:** Almacenar los contactos sin duplicados y en orden alfabético mediante `std::set`.
3. **Solución con map:** Asociar el nombre de cada contacto con su información (teléfono y correo electrónico) mediante `std::map`, permitiendo buscar contactos por su nombre.

Las tres soluciones deben permitir mostrar la agenda y buscar un contacto por su nombre. El propósito es comparar cómo se resuelve el mismo problema manualmente y mediante estructuras de datos de la biblioteca estándar de C++.


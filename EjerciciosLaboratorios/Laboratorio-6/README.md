## Enunciado del Problema

Una empresa que ofrece servicios de almacenamiento desea implementar un **sistema inteligente de casilleros** para que las personas puedan guardar sus pertenencias de manera segura y organizada. Cada casillero se identifica mediante un **número único** y debe permitir controlar su disponibilidad, asignación y liberación.

El sistema debe permitir registrar los casilleros ocupados, consultar su disponibilidad, asignarlos a una persona y liberarlos cuando ya no sean necesarios.

Se requiere utilizar un `struct` para representar los datos de la persona asignada a cada casillero:

1. **Solución manual:** Implementar una tabla hash desde cero, sin uso de librerías de contenedores, utilizando un arreglo de buckets, una función hash (`número % tamaño`) y listas enlazadas para resolver las colisiones mediante encadenamiento separado.
2. **Solución con unordered_set:** Almacenar los casilleros ocupados mediante `std::unordered_set`, evitando registros duplicados. Se define una función hash propia (`CasilleroHash`) y el operador `==` para que el número del casillero funcione como clave.
3. **Solución con unordered_map:** Asociar el número del casillero (clave) con los datos de la persona asignada (valor) mediante `std::unordered_map`.

### Funciones a implementar

- **Asignar Casillero:** registra un casillero como ocupado y lo asigna a una persona.
- **Buscar Casillero:** comprueba si un casillero está ocupado y, si corresponde, muestra los datos de la persona asignada.
- **Liberar Casillero:** elimina el registro del casillero para que pueda utilizarse nuevamente.
- **Mostrar Casilleros:** muestra todos los casilleros que se encuentran ocupados.

### Validaciones

- Comprobar que el número del casillero sea positivo.
- Evitar registrar números de casilleros duplicados.
- Verificar que el casillero esté ocupado antes de liberarlo.
- Comprobar que los datos de la persona no estén vacíos.

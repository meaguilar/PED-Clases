
## Biblioteca de Canciones – Gestión de Playlist

Una biblioteca musical necesita gestionar las canciones de su colección personal. Se requiere
registrar cada canción con su información y poder navegar por la colección en ambos sentidos.

### Estructura de datos

El sistema utilizará una **lista doblemente enlazada** con dos estructuras:

**Struct Cancion:** almacena los datos de cada canción
- `titulo` (string): nombre de la canción
- `artista` (string): nombre del artista o grupo
- `duracion` (float): duración en minutos
- `genero` (string): género musical

**Struct Nodo:** representa cada nodo de la lista
- `cancion` (struct Cancion): dato almacenado
- `siguiente` (Nodo*): puntero al siguiente nodo
- `anterior` (Nodo*): puntero al nodo anterior

### Funciones implementadas

1. `pedirDatosCancion()` → solicita al usuario los datos de una canción y retorna el struct
2. `agregarCancion(Cancion cancion)` → recibe un struct Cancion y lo añade al final de la lista
3. `mostrarPlaylist()` → lista todas las canciones (de inicio a fin)
4. `mostrarPlaylistInversa()` → lista todas las canciones (de fin a inicio)
5. `buscarCancion(Cancion cancion)` → recibe un struct con el título y busca la canción en la lista
6. `eliminarCancion(Cancion cancion)` → recibe un struct con el título y elimina la canción de la lista
7. `calcularDuracionTotal()` → calcula la duración total de la playlist
8. `clasificarDuracion(float duracion)` → clasifica una canción como "Corta", "Media" o "Larga"
9. `liberarMemoria()` → libera toda la memoria asignada al salir del programa

### Cálculos automáticos

- **Duración total de la playlist**: suma de todas las duraciones de canciones
- **Clasificación por duración**: cada canción se clasifica como:
  - "Corta" si duración < 3 min
  - "Media" si 3 <= duración < 5 min
  - "Larga" si duración >= 5 min

### Estructura del menú

```
=== Biblioteca de Canciones ===
1. Agregar canción
2. Mostrar playlist (inicio -> fin)
3. Mostrar playlist (fin -> inicio)
4. Buscar canción
5. Eliminar canción
6. Duración total de playlist
0. Salir
```

### Paso de struct como parámetro

Las funciones `agregarCancion`, `buscarCancion` y `eliminarCancion` reciben el struct `Cancion`
como parámetro. Esto permite que los datos sean manipulados de forma clara y estructurada:

- `agregarCancion(nueva)` → recibe una canción completa con todos sus datos
- `buscarCancion(buscada)` → recibe solo el título lleno para realizar la búsqueda
- `eliminarCancion(eliminada)` → recibe solo el título lleno para realizar la eliminación

>💡 El menú es opcional y solo sirve para probar de forma interactiva cómo cambian los resultados. El objetivo principal es comprender el funcionamiento de las listas doblemente enlazadas y el paso de estructuras como parámetros.

---

**En este ejercicio se usa una lista doblemente enlazada para almacenar los registros.
Esto permite recorrerlos de inicio a fin o de fin a inicio, y facilita realizar
operaciones de inserción, eliminación o modificación en cualquier parte de la lista.**

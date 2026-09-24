
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

### Funciones  por implementar

1. `agregarCancion()` → añade una canción al final de la lista
2. `mostrarPlaylist()` → lista todas las canciones (de inicio a fin)
3. `mostrarPlaylistInversa()` → lista todas las canciones (de fin a inicio)
4. `buscarCancion()` → busca una canción por título y muestra su información
5. `eliminarCancion()` → elimina una canción de la lista por título
6. `contarCanciones()` → retorna la cantidad total de canciones
7. `calcularDuracionTotal()` → calcula la duración total de la playlist

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
6. Contar canciones
7. Duración total de playlist
0. Salir
```

>💡 El menú es opcional y solo sirve para probar de forma interactiva cómo cambian los resultados. El objetivo principal es comprender el funcionamiento de las listas doblemente enlazadas.

---

**En este ejercicio se usa una lista doblemente enlazada para almacenar los registros.
Esto permite recorrerlos de inicio a fin o de fin a inicio, y facilita realizar
operaciones de inserción, eliminación o modificación en cualquier parte de la lista.**

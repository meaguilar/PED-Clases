
# Granja solar – Batería de respaldo

Una comunidad que utiliza paneles solares controla la carga de su batería para administrar la energía disponible. Se requiere un módulo que permita registrar la energía generada por los paneles y descontar la energía consumida. Tomar en cuenta la unidad de medida **Wh (vatios-hora):** unidad de energía, indica una cantidad de energía almacenada o utilizada.

A partir de las funciones proporcionadas, implemente las tres operaciones solicitadas, aplicando correctamente cada mecanismo de paso de parámetros.

## Funciones por implementar

-   La función **`ConsultarCarga(int carga)`** deberá mostrar la carga recibida, sin modificar la carga original.
    
-   La función **`CargarBateria(int &carga, int Wh)`** deberá aumentar la carga de la batería, modificando el valor mediante referencia.
    
-   La función **`ConsumirEnergia(int *carga, int Wh)`** deberá disminuir la carga de la batería, modificando el valor mediante puntero.

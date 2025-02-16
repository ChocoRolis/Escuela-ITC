# Ejercicio05: Comunicación entre procesos mediante señales

## Descripción del ejercicio

Desarrolla dos scripts: un servidor (`recibe.sh`) que espera recibir señales y un cliente (`envia.sh`) que envía señales a ese proceso. El servidor debe capturar la señal `SIGINT` y mostrar un mensaje. El cliente debe enviar `SIGINT` y luego `SIGTERM` al servidor.

## Solución implementada

### `recibe.sh` (Servidor)

Este script actúa como un servidor que espera señales. Utiliza `trap` para capturar la señal `SIGINT` y mostrar un mensaje cuando la recibe. Luego, entra en un bucle infinito, esperando señales.

### `envia.sh` (Cliente)

Este script actúa como un cliente que envía señales al servidor. Primero, solicita al usuario que ingrese el PID del proceso al que se enviarán las señales. Luego, envía la señal `SIGINT` al proceso especificado y espera 2 segundos. Finalmente, envía la señal `SIGTERM` para terminar el proceso.

## Ejemplo de ejecución

1.  **Ejecutar el servidor (`recibe.sh`) en una terminal:**

    ```bash
    bash recibe.sh
    ```

    El script mostrará:

    ```
    PID: 12345
    Esperando señal...
    ```

    (Donde 12345 es el PID del script)

2.  **Ejecutar el cliente (`envia.sh`) en otra terminal:**

    ```bash
    bash envia.sh
    ```

    El script preguntará:

    ```
    Escribe el nombre del proceso a mandar la señal:
    ```

3.  **Ingresar el PID del servidor (12345) y presionar Enter.**

    El cliente enviará la señal `SIGINT` al servidor.

4.  **En la terminal del servidor, se verá:**

    ```
    Señal recibida con exito!
    ```

5.  **Después de 2 segundos, el cliente enviará la señal `SIGTERM` al servidor.**

6.  **El servidor terminará su ejecución.**

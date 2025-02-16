# Ejercicio09: Detención con señal específica (SIGQUIT)

## Descripción del ejercicio

Crea un script que se detenga con una señal específica. Este script solo se detendrá cuando reciba la señal `SIGQUIT`.

## Solución implementada

El script utiliza el comando `trap` para capturar las señales `SIGQUIT`, `SIGTERM` y `SIGINT`.

* Cuando se recibe `SIGQUIT`, se ejecuta la función que imprime "bye" y luego termina el script con `exit 0`.
* Cuando se recibe `SIGTERM` o `SIGINT`, se ejecuta la función que imprime "prueba otro interrupt".

El script imprime su PID al inicio para que el usuario pueda enviarle señales fácilmente. Luego entra en un bucle infinito, esperando las señales.

## Ejemplo de ejecución

1.  **Ejecutar el script:**

    ```bash
    bash script.sh
    ```

    El script mostrará:

    ```
    PID: 12345
    Esperando seniales...
    ```

2.  **Enviar `SIGTERM` (en otra terminal):**

    ```bash
    kill -TERM 12345
    ```

    El script mostrará:

    ```
    prueba otro interrupt
    ```

3.  **Enviar `SIGINT` (en otra terminal):**

    ```bash
    kill -INT 12345
    ```

    El script mostrará:

    ```
    prueba otro interrupt
    ```

4.  **Enviar `SIGQUIT` (en otra terminal):**

    ```bash
    kill -QUIT 12345
    ```

    El script mostrará:

    ```
    bye
    ```

    Y luego terminará.

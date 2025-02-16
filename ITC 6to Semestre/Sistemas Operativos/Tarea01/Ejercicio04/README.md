# Ejercicio04: Captura de múltiples señales con manejo especial para SIGTERM

## Descripción del ejercicio

Crea un script que capture `SIGTERM`, `SIGXCPU` y `SIGVTALRM` en donde se muestre un mensaje antes de recibir la señal, este script manejará la señal `SIGTERM` para mostrar un mensaje de salida antes de cerrar el proceso.

## Solución implementada

El script utiliza el comando `trap` para capturar las señales `SIGXCPU`, `SIGVTALRM` y `SIGTERM`. 

* Cuando se recibe `SIGXCPU` o `SIGVTALRM`, se ejecuta la función `trapper()`, que simplemente imprime " Señal recibida!". 
* Cuando se recibe `SIGTERM`, se ejecuta la función `term_trapper()`, que imprime " Bye" y luego termina el script con `exit 0`.

El script imprime su PID al inicio para que el usuario pueda enviarle señales fácilmente. Luego entra en un bucle infinito donde espera las señales.

## Ejemplo de ejecución

1.  **Ejecutar el script:**

    ```bash
    bash script.sh
    ```

    El script mostrará:

    ```
    PID: 12345
    Esperando señales...
    ```

2.  **Enviar `SIGXCPU` (en otra terminal):**

    ```bash
    kill -XCPU 12345
    ```

    El script mostrará:

    ```
     Señal recibida!
    ```

3.  **Enviar `SIGVTALRM` (en otra terminal):**

    ```bash
    kill -VTALRM 12345
    ```

    El script mostrará:

    ```
     Señal recibida!
    ```

4.  **Enviar `SIGTERM` (en otra terminal):**

    ```bash
    kill -TERM 12345
    ```

    El script mostrará:

    ```
     Bye
    ```

    Y luego terminará.

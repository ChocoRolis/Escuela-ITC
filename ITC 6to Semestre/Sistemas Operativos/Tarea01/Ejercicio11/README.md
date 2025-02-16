# Ejercicio11: Esperando y mostrando señales

## Descripción del ejercicio

Crea un script que espere y muestre señales. Este script debe de mostrar qué señales recibe (8 señales como mínimo).

## Solución implementada

El script utiliza el comando `trap` para capturar varias señales: `SIGHUP`, `SIGINT`, `SIGQUIT`, `SIGILL`, `SIGUSR1`, `SIGUSR2` y `SIGSTOP`. Cuando se recibe cualquiera de estas señales, se ejecuta la función `trapper()`, que imprime un mensaje indicando qué señal se recibió.

El script imprime su PID al inicio para que el usuario pueda enviarle señales fácilmente. Luego entra en un bucle infinito, esperando las señales.

**Nota importante:** `SIGSTOP` no puede ser capturada por un script de Bash. Por lo tanto, el mensaje "Señal SIGSTOP recibida!" no se mostrará cuando se intente detener el script con `SIGSTOP`.

## Ejemplo de ejecución

1.  **Ejecutar el script:**

    ```bash
    bash script.sh
    ```

    El script mostrará:

    ```
    PID: 12345
    Esperando Señales...
    ```

2.  **Enviar `SIGHUP` (en otra terminal):**

    ```bash
    kill -HUP 12345
    ```

    El script mostrará:

    ```
    Señal SIGHUP recibida!
    ```

3.  **Enviar `SIGINT` (en otra terminal):**

    ```bash
    kill -INT 12345
    ```

    El script mostrará:

    ```
    Señal SIGINT recibida!
    ```

4.  **Enviar `SIGQUIT` (en otra terminal):**

    ```bash
    kill -QUIT 12345
    ```

    El script mostrará:

    ```
    Señal SIGQUIT recibida!
    ```

5.  **Enviar `SIGILL` (en otra terminal):**

    ```bash
    kill -ILL 12345
    ```

    El script mostrará:

    ```
    Señal SIGILL recibida!
    ```

6.  **Enviar `SIGUSR1` (en otra terminal):**

    ```bash
    kill -USR1 12345
    ```

    El script mostrará:

    ```
    Señal SIGUSR1 recibida!
    ```

7.  **Enviar `SIGUSR2` (en otra terminal):**

    ```bash
    kill -USR2 12345
    ```

    El script mostrará:

    ```
    Señal SIGUSR2 recibida!
    ```

8.  **Intentar enviar `SIGSTOP` (en otra terminal):**

    ```bash
    kill -STOP 12345
    ```

    El script se detendrá inmediatamente, pero no mostrará "Señal SIGSTOP recibida!" porque `SIGSTOP` no se puede capturar.

9.  **Continuar la ejecución después de `SIGSTOP` (en otra terminal):**

    ```bash
    kill -CONT 12345
    ```

    El script continuará su ejecución.

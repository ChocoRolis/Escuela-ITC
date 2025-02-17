# Ejercicio02: Captura de SIGTERM, SIGSTOP y SIGCHLD (Corregido)

## Descripción del ejercicio

Crea un script que manejará las señales `SIGTERM`, `SIGSTOP` y `SIGCHLD` para mostrar un mensaje de salida antes de detectar la señal en el proceso.

## Solución implementada

El script utiliza el comando `trap` para capturar las señales `SIGTERM` y `SIGCHLD`. Cuando se recibe cualquiera de estas señales, se ejecuta la función `trapper()`, que imprime el mensaje " senial recibida!". El script continúa ejecutándose en un bucle infinito, durmiendo durante 2 segundos en cada iteración. El script imprime su PID al inicio para facilitar el envío de señales.

**Nota importante:** La señal `SIGSTOP` no puede ser capturada por un script de Bash. Por lo tanto, el mensaje " senial recibida!" no se mostrará cuando se intente detener el script con `SIGSTOP`. La señal `SIGCHLD` se genera cuando un proceso hijo termina o se detiene. En este script, no se crean procesos hijos, por lo que esta señal no se generará a menos que el script sea modificado para crear procesos hijos.

## Ejemplo de ejecución

1.  **Ejecutar el script:**

    ```bash
    bash script.sh
    ```

    El script mostrará un mensaje similar a:

    ```
    Esperando seniales... :) (pid: 12345)
    ```

2.  **Enviar la señal SIGTERM (en otra terminal):**

    ```bash
    kill -TERM 12345
    ```

    El script mostrará:

    ```
     senial recibida!
    ```

3.  **Intentar detener con SIGSTOP (en otra terminal):**

    ```bash
    kill -STOP 12345
    ```

    El script se detendrá inmediatamente, pero no mostrará " senial recibida!" porque `SIGSTOP` no se puede capturar.

4.  **Continuar la ejecución después de SIGSTOP (en otra terminal):**

    ```bash
    kill -CONT 12345
    ```

    El script continuará su ejecución.

5.  **Enviar la señal SIGCHLD (no tendrá efecto directo en este script):**

    ```bash
    kill -CHLD 12345
    ```

    En este script específico, no se generará el mensaje " senial recibida!" porque no hay procesos hijos involucrados.

6. **Terminar el proceso con SIGTERM**

    ```bash
    kill -TERM 12345
    ```

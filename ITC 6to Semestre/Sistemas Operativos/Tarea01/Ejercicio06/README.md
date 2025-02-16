# Ejercicio06: Reinicio de Script con SIGHUP

## Descripción del ejercicio

Crea un script que se reinicie automáticamente al recibir la señal `SIGHUP`.

## Solución implementada

El script utiliza el comando `trap` para capturar la señal `SIGHUP`. Cuando se recibe esta señal, se ejecuta la función `trapper()`, que imprime "Reiniciando..." y luego utiliza `exec "$0"` para reemplazar el proceso actual con una nueva instancia del mismo script.

El bucle `for i in {1..3}` al inicio del script simplemente imprime los números del 1 al 3 con un retraso de 1 segundo entre cada número. Esto se utiliza para demostrar visualmente que el script se ha reiniciado cuando se recibe la señal `SIGHUP`. Después del bucle `for`, el script imprime su PID y entra en un bucle infinito, esperando la señal `SIGHUP`.

## Ejemplo de ejecución

1.  **Ejecutar el script:**

    ```bash
    bash script.sh
    ```

    El script mostrará:

    ```
    1
    2
    3
    PID: 12345
    Esperando señal...
    ```

2.  **Enviar la señal `SIGHUP` (en otra terminal):**

    ```bash
    kill -HUP 12345
    ```

    El script se reiniciará y mostrará:

    ```
    Reiniciando...
    1
    2
    3
    PID: 67890
    Esperando señal...
    ```

    (Observa que el PID ha cambiado, lo que indica que el script se ha reiniciado).

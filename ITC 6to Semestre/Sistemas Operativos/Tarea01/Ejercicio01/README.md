# Ejercicio01: Captura de SIGINT

## Descripción del ejercicio

Crea un script que se ejecute en un ciclo infinito y que capture la señal SIGINT (Ctrl + C) para evitar que el usuario lo interrumpa fácilmente.

## Solución implementada

El script utiliza el comando `trap` para capturar la señal `SIGINT` (generada al presionar Ctrl+C). Cuando se recibe esta señal, en lugar de terminar el script, se ejecuta la función `trapper()`, que imprime el mensaje "¡Esto no funcionará!". El script continúa ejecutándose en un bucle infinito, mostrando el mensaje "Usa SIGTERM para terminarme, pid: $$" cada 2 segundos. Para terminar el script, el usuario debe usar la señal `SIGTERM` (por ejemplo, con el comando `kill <pid>`).

## Ejemplo de ejecución

1.  **Ejecutar el script:**

    ```bash
    bash script.sh
    ```

2.  **Intentar interrumpir con Ctrl+C:**

    ```bash
    ^C ¡Esto no funcionará!
    Usa SIGTERM para terminarme, pid: 12345
    ```

    (Donde 12345 es el PID del script)

3.  **Terminar el script con SIGTERM (en otra terminal):**

    ```bash
    kill -TERM 12345
    ```

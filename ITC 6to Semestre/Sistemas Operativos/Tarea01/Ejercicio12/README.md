# Ejercicio12: Matar un proceso con otro script (SIGKILL)

## Descripción del ejercicio

Mata un proceso con otro script. Este script permitirá ingresar el PID de un proceso y enviarle la señal `SIGKILL` como lo vimos en clase, solo que éste debe de detenerse hasta que el usuario así lo decida.

## Solución implementada

El script solicita al usuario que ingrese el PID del proceso que desea terminar. Luego, pregunta si está seguro de querer terminar el proceso. Si el usuario ingresa "y" o "Y", el script envía la señal `SIGKILL` al proceso especificado. De lo contrario, el script termina sin hacer nada.

## Ejemplo de ejecución

1.  **Ejecutar el script:**

    ```bash
    bash script.sh
    ```

2.  **Ingresar el PID del proceso que se desea terminar:**

    ```
    Dame el PID del proceso y mandare un SIGKILL cuando gustes: 12345
    ```

3.  **Confirmar la terminación del proceso:**

    ```
    Quieres matara al proceso 12345? [y/N] y
    ```

    El script enviará la señal `SIGKILL` al proceso con PID 12345, terminando el proceso inmediatamente.

4.  **Ejecutar el script y no confirmar la terminación:**

    ```bash
    bash script.sh
    ```

    ```
    Dame el PID del proceso y mandare un SIGKILL cuando gustes: 12345
    Quieres matara al proceso 12345? [y/N] n
    ```

    El script terminará sin enviar la señal `SIGKILL`.

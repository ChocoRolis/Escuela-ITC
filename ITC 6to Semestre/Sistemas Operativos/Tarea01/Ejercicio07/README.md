# Ejercicio07: Proceso en segundo plano y recuperación

## Descripción del ejercicio

Crea un proceso en segundo plano y recupéralo en primer plano. Este ejercicio muestra cómo ejecutar un script en segundo plano, pausarlo y reanudarlo.

## Solución implementada

El script imprime un mensaje indicando que se está ejecutando en segundo plano, mostrando su PID. Luego, entra en un bucle infinito donde imprime "hola" cada 2 segundos. Para ejecutarlo en segundo plano, se utiliza el operador `&` al final del comando. Para traerlo de vuelta al primer plano, se utilizan los comandos `jobs`, `fg`, y opcionalmente `bg` para controlarlo.

## Ejemplo de ejecución

1.  **Ejecutar el script en segundo plano:**

    ```bash
    bash script.sh &
    ```

    El script mostrará:

    ```
    Estoy en el background! 12345
    [1] 12345
    ```

    (Donde 12345 es el PID del script). El `[1]` indica el número de trabajo (job).

2.  **Ver los trabajos en segundo plano:**

    ```bash
    jobs
    ```

    Mostrará:

    ```
    [1]+ Running bash script.sh
    ```

3.  **Traer el trabajo al primer plano:**

    ```bash
    fg %1
    ```

    (o simplemente `fg` si es el único trabajo). El script continuará imprimiendo "hola" en la terminal.

4.  **Pausar el trabajo (Ctrl+Z):**

    ```
    ^Z
    [1]+ Stopped bash script.sh
    ```

5.  **Enviar el trabajo al segundo plano:**

    ```bash
    bg %1
    ```

    (o simplemente `bg` si es el único trabajo). El script continuará ejecutándose en segundo plano.

6.  **Traerlo nuevamente al primer plano:**

    ```bash
    fg %1
    ```

7.  **Terminar el script (Ctrl+C):**

    ```
    ^C
    ```

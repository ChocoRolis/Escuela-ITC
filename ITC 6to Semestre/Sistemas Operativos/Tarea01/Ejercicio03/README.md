# Ejercicio03: Captura de SIGINT con contador

## Descripción del ejercicio

Capturar SIGINT (Ctrl + C) y Evitar la Interrupción: Crea un script que se ejecute en un ciclo infinito y que capture la señal SIGINT (Ctrl + C) N cantidad de veces para evitar que el usuario lo interrumpa fácilmente.

## Solución implementada

El script utiliza un contador (`cont`) para controlar cuántas veces se ha capturado la señal `SIGINT`.  Cada vez que se presiona Ctrl+C, se ejecuta la función `trapper()`. Esta función incrementa el contador e imprime un mensaje. Si el contador alcanza un valor de 3, el script termina con `exit 0`.  Mientras el contador sea menor que 3, el script continúa ejecutándose en un bucle infinito, mostrando un mensaje que indica cuántas veces más se debe presionar Ctrl+C para terminar el script.

## Ejemplo de ejecución

1.  **Ejecutar el script:**

    ```bash
    bash script.sh
    ```

2.  **Presionar Ctrl+C una vez:**

    ```
    Terminame, usa Ctrl-c 3 veces mas
    SIGINT recibido!
    Terminame, usa Ctrl-c 2 veces mas 
    ```

3.  **Presionar Ctrl+C dos veces más:**

    ```
    SIGINT recibido!
    Terminame, usa Ctrl-c 1 veces mas
    SIGINT recibido!
    ```

    El script termina después de la tercera vez que se presiona Ctrl+C.

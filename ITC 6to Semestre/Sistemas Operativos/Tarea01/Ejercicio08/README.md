# Ejercicio08: Monitoreo y auto-terminación de un proceso largo

## Descripción del ejercicio

Crea un script que monitoree su propio tiempo de ejecución y se cierre automáticamente si supera cierto tiempo (en este caso, 10 segundos).

## Solución implementada

El script utiliza el comando `date +%s` para obtener el número de segundos transcurridos desde el Epoch (1 de enero de 1970) al inicio del script y lo almacena en la variable `tiempo_inicio`. Luego, entra en un bucle infinito donde obtiene el tiempo actual y calcula el tiempo transcurrido restando el tiempo de inicio. Si el tiempo transcurrido es mayor o igual a 10 segundos, el script imprime "bye" y termina. De lo contrario, duerme durante 1 segundo y continúa el bucle.

## Ejemplo de ejecución

1.  **Ejecutar el script:**

    ```bash
    bash script.sh
    ```

2.  **El script mostrará:**

    ```
    Este programa terminara en 10 segundos
    ```

3.  **Después de 10 segundos, el script mostrará:**

    ```
    bye
    ```

    Y luego terminará.

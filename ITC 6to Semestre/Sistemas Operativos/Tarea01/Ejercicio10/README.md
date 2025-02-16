# Ejercicio10: Cola de procesos con señales (SIGUSR1)

## Descripción del ejercicio

Crea una cola de procesos con señales. En este script se debe de manejar una cola de tareas y debe de procesar una por una al recibir `SIGUSR1`.

## Solución implementada

El script utiliza un archivo de texto llamado `tareas.txt` para almacenar una cola de tareas, donde cada línea representa una tarea a ejecutar. El script captura la señal `SIGUSR1` y, cuando la recibe, ejecuta la función `tareas()`. Esta función verifica si el archivo `tareas.txt` existe. Si existe, lee cada línea del archivo, la ejecuta usando `eval`, y espera 2 segundos antes de procesar la siguiente tarea. Al finalizar, imprime "Tareas completadas con exito!" y termina. Si el archivo no existe, imprime "No existe archivo de tareas" y termina.

## Ejemplo de ejecución

1.  **Crear el archivo `tareas.txt`:**

    ```bash
    echo "ls" > tareas.txt
    echo "pwd" >> tareas.txt
    echo 'echo "hello world"' >> tareas.txt
    ```

2.  **Ejecutar el script:**

    ```bash
    bash script.sh
    ```

    El script mostrará:

    ```
    PID: 12345
    Esperando señal...
    ```

3.  **Enviar la señal `SIGUSR1` (en otra terminal):**

    ```bash
    kill -USR1 12345
    ```

4.  **El script procesará las tareas y mostrará:**

    ```
    Senial recibida, empezando tareas...
    Procesando tarea: ls
    <salida del comando ls>
    Procesando tarea: pwd
    <salida del comando pwd>
    Procesando tarea: echo "hello world"
    hello world
    Tareas completadas con exito!
    ```

    Y luego terminará.

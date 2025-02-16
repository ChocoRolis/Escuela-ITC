#!/bin/bash

cola_tareas="tareas.txt"

echo "PID: $$"
echo "Esperando señal..."

tareas() {
	if [ -f "$cola_tareas" ]; then
		lineas=$(wc -l < $cola_tareas)
		
		for i in $(seq 1 $lineas); do
			tarea=$(sed -n "${i}p" "$cola_tareas")  
			echo "Procesando tarea: $tarea"
			eval "$tarea"
			sleep 2  
		done

		echo "Tareas completadas con exito!"
		exit 0
	else
		echo "No existe archivo de tareas"
		exit 1
	fi
}

trap 'echo "Senial recibida, empezando tareas..."; tareas' SIGUSR1

while true; do
	sleep 1  
done


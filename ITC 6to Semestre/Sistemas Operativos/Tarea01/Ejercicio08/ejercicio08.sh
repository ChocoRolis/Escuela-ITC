#!/bin/bash

# numero de segundos desde Epoch, la fecha de referencia de sistemas UNIX
tiempo_inicio=$(date +%s)

echo "Este programa terminara en 10 segundos"

while true; do
	tiempo_actual=$(date +%s)
	tiempo_transcurrido=$((tiempo_actual - tiempo_inicio))
	
	if [ $tiempo_transcurrido -ge 10 ]; then
		echo "bye"
		exit 0
	fi

	sleep 1
done

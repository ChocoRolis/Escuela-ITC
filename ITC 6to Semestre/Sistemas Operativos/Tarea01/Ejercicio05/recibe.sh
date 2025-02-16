#!/bin/bash

trap 'echo "Señal recibida con exito!"' SIGINT

echo "PID: $$"
echo "Esperando señal..."

while true; do
	sleep 1
done

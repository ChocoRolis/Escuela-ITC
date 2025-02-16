#!/bin/bash

trap 'echo "bye"; exit 0' SIGQUIT
trap 'echo "prueba otro interrupt"' SIGTERM SIGINT

echo "PID: $$"
echo "Esperando seniales..."

while true; do
	sleep 1
done

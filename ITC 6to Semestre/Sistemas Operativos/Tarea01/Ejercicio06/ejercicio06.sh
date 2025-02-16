#!/bin/bash

trapper() {
	echo "Reiniciando..."
	exec "$0"
}

trap trapper SIGHUP

for i in {1..3}; do
	echo "$i"
	sleep 1
done

echo "PID: $$"
echo "Esperando señal..."

while true; do
	sleep 1
done

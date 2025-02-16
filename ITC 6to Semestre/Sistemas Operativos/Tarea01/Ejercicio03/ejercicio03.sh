#!/bin/bash

cont=0

trapper() {
	echo " SIGINT recibido!"

	if [ $((++cont)) -ge 3 ]; then
		exit 0
	fi
}

trap trapper SIGINT

while true; do
	echo "Terminame, usa Ctrl-c $((3 - cont)) veces mas"
	sleep 1
done

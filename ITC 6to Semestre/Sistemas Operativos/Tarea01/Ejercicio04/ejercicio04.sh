#!/bin/bash

trapper() {
	echo " Señal recibida!"
}

term_trapper(){
	echo " Bye"
	exit 0
}

trap trapper SIGXCPU SIGVTALRM
trap term_trapper SIGTERM

echo "PID: $$"
echo "Esperando señales..."

while true; do
	sleep 2
done

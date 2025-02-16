#!/bin/bash

trapper() {
	echo "Señal $1 recibida!"
}

trap trapper SIGHUP
trap trapper SIGINT
trap trapper SIGQUIT
trap trapper SIGILL
trap trapper SIGUSR1
trap trapper SIGUSR2
trap trapper SIGQUIT
trap trapper SIGSTOP

echo "PID: $$"
echo "Esperando Señales..."

while true; do
	sleep 1
done

#!/bin/bash

trapper() {
	echo " senial recibida!"
}

trap trapper SIGTERM SIGSTOP SIGCHLD

echo "Esperando seniales... :) (pid: $$)"

while true; do
	sleep 2
done

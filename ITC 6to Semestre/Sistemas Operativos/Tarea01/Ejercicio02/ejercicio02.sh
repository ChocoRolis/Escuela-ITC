#!/bin/bash

trapper() {
	echo " nO"
}

trap trapper SIGTERM SIGSTOP SIGCHLD

echo "Intenta detenerme :) (pid: $$)"

while true; do
	sleep 2
done

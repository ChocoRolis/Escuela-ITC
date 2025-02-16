#!/bin/bash

trapper() {
	echo " Esto no funcionara!"
}

trap trapper SIGINT

while true; do
	echo "Usa SIGTERM para terminarme, pid: $$"
	sleep 2
done

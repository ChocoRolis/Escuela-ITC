#!/bin/bash

read -p "Dame el PID del proceso y mandare un SIGKILL cuando gustes: " pid
read -p "Quieres matar al proceso $pid? [y/N] " ans 

if [ $ans = "y" ] || [ $ans = "Y" ]; then
	kill -KILL $pid  
	echo "Proceso $pid terminado con exito"
else
	exit 0
fi


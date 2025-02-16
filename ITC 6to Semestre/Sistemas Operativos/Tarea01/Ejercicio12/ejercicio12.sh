#!/bin/bash

read -p "Dame el PID del proceso y mandare un SIGKILL cuando gustes: " pid
read -p "Quieres matara al proceso $pid? [y/N] " ans 

if [ $ans== "y" || $ans == "Y" ]; then
	kill -KILL $pid  
else
	exit 0
fi


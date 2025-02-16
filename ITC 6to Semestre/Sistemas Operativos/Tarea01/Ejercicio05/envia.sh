#!/bin/bash

read -p "Escribe el nombre del proceso a mandar la señal: " senial

kill -SIGINT $senial
sleep 2
kill -TERM $senial

#!/bin/bash

listar_contenido() {
	echo "\nSenial TERM recibida"
	read -p "Ingrese el path absoluto del directorio a visualizar: " dirpath

	if [ -d $dirpath ]; then
		echo "\n El contenido del directorio es: $dirpath: "
		ls -lia $dirpath
	else
		echo "\n El path $dirpath absoluto no existe o es incorrecto"
	fi
	
	exit 0	
}
 
trap listar_contenido TERM

echo "Ejecutando proceso. Use la senial KILL -TERM para enviar senial"
echo "PID del proceso: $$"

while true; do
	sleep 1;
done

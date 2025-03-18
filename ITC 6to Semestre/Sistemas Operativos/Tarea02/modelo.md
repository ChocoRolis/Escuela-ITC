1. se recibe senial usr1
3. input directorio con archivos .txt
4. 
5. creo los pipes
	1. cada uno con un pointer a los archivos a leer?
6. input numero de forks
7. se abre directorio
8. creo los forks
	1. con un if y cuidado de no crear de mas
9. con un for leo cada archivo
10. aplico una funcion con todos los regex a analizar
11. padre espera cada uno con waitpid()

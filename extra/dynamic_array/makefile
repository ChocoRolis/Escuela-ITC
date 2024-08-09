
all:
	gcc -c -Wall -Werror -Wextra dyarray.c 
	ar -rc libdyarray.a *.o
	gcc main.c -L . -ldyarray -o main

shared:
	gcc -c -Wall -Werror -Wextra dyarray.c -fPIC
	gcc -shared *.o -o libdyarray.so
	gcc main.c -L . -ldyarray -o main

clean:
	rm *.o
	rm *.a
	rm main

clean_shared:
	rm *.o
	rm *.so
	rm main

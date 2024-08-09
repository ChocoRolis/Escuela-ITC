
all:
	gcc -c -Wall -Werror -Wextra permutations.c 
	ar -rc libpermutations.a *.o
	gcc main.c -L . -lpermutations -o main

lib:
	gcc -c -Wall -Werror -Wextra permutations.c 
	ar -rc libpermutations.a *.o
	rm *.o

clean:
	rm *.o
	rm *.a
	rm main

cleanlib:
	rm *.a

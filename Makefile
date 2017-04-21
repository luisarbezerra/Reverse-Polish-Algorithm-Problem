pilha: pilha.o main.o resolucao.o
	gcc pilha.o main.o resolucao.o -o TP0 -Wall -Wextra -Werror -std=c99 -pedantic -lm
main.o: main.c pilha.h resolucao.h
	gcc -g -c main.c -Wall -Wextra -Werror -std=c99 -pedantic -lm
pilha.o: pilha.h pilha.c
	gcc -g -c pilha.c -Wall -Wextra -Werror -std=c99 -pedantic -lm
resolucao.o: resolucao.h resolucao.c
	gcc -g -c resolucao.c -Wall -Wextra -Werror -std=c99 -pedantic -lm
clean:
	rm TP0
	rm *.o

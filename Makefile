clean:	tp
	rm *.o

tp:	main.o	funcoes.o
	gcc main.o funcoes.o -o tp -lm

main.o:	main.c
	gcc main.c -c

funcoes.o:	funcoes.c
	gcc funcoes.c -c

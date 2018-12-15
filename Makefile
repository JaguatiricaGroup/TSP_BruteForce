args = -std=c99 -lm -Wall -lm -g  #-J5 -O3
diretorioCodigo = ./src/
diretorioBin = ./bin/
CC = gcc

all:
	$(CC) $(args) -c  $(diretorioCodigo)*.c
	$(CC) $(args) *.o  main.c -o trabalhoApa
clean:
	rm ./*.o
	rm ./trabalhoApa

Opt:
	$(CC) $(args) -J5 -O3 -c  $(diretorioCodigo)*.c
	$(CC) $(args) -J5 -O3 *.o  main.c -o trabalhoApa


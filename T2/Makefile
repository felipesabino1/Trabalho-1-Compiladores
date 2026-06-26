CC = gcc
CFLAGS = -Wall -g

all: g-v2

g-v2: scanner.o parser.o semantico.o tabela.o tipos.o
	$(CC) $(CFLAGS) -o g-v2 scanner.o parser.o semantico.o tabela.o tipos.o -lfl

parser.c: parser.y
	bison -d --header=tokens.h -o parser.c parser.y

parser.o: parser.c
	$(CC) $(CFLAGS) -c parser.c

scanner.c: scanner.l parser.c
	flex -o scanner.c scanner.l

scanner.o: scanner.c
	$(CC) $(CFLAGS) -c scanner.c -Wno-unused-function

semantico.o: semantico.c semantico.h tabela.h tipos.h
	$(CC) $(CFLAGS) -c semantico.c

tabela.o: tabela.c tabela.h
	$(CC) $(CFLAGS) -c tabela.c

tipos.o: tipos.c tipos.h
	$(CC) $(CFLAGS) -c tipos.c


clean:
	rm -f *.o g-v2 parser.c tokens.h scanner.c

.PHONY: all clean

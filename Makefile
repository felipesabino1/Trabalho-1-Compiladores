CC = gcc-14
g-v1:  parser.o scanner.o tipos.o
	$(CC) parser.o scanner.o tipos.o -o g-v1
parser.o: parser.c
	$(CC) -c parser.c -o parser.o
parser.c:  parser.y
	bison --header=tokens.h -o parser.c parser.y
scanner.o: scanner.c
	$(CC) -c scanner.c -o scanner.o
scanner.c: scanner.l
	flex  -o scanner.c  scanner.l
tipos.o: tipos.c
	$(CC) -c tipos.c -o tipos.o
clean:
	rm *.o  parser.c scanner.c tokens.h
run:
	./g-v1 teste.g

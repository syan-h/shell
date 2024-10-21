

test_lexer: lexer.c lexer.h test_lexer.c
	gcc lexer.c test_lexer.c -o  test_lexer.o
	./test_lexer.o


main: main.c lexer.c lexer.h
	gcc main.c lexer.c -o main.o
	./main.o

clean:
	rm *.o

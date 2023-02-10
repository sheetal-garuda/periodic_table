a.out:grep.o main.o
	gcc grep.o main.o
grep.o:grep.c grep.h
	gcc -c grep.c
main.o:main.c grep.h
	gcc -c main.c
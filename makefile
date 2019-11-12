all: proba

proba: proba.o
	gcc -o proba proba.o

proba.o: proba.c
	gcc -c proba.c 

clean:
	rm proba.o proba

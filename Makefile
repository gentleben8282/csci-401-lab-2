# Reference: https://riptutorial.com/c/example/3250/calling-a-function-from-another-c-file

signals: signal.c timer.c
	gcc -Wall -c signal.c
	gcc -Wall -c timer.c
	gcc -o signals timer.o signal.o
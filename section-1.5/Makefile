All:
	gcc compiler.c -o compiler
	./compiler
	gcc -c runtime.c -o runtime.o
	as output.s -o output.o
	gcc -o program output.o runtime.o

.PHONY: reset clean objrm

reset : clean
	rm program
clean :
	rm *.[os]
objrm :
	rm *.o

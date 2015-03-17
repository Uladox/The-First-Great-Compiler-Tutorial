All:
	gcc compiler.c scheme_utils.c -o compiler
	./compiler
	gcc -c runtime.c -o runtime.o
	gcc -c scheme_utils.c -o scheme_utils.o
	as output.s -o output.o
	gcc -o program output.o runtime.o scheme_utils.o

.PHONY: reset clean objrm

reset : clean
	rm program
	rm compiler
clean :
	rm *.[os]
objrm :
	rm *.o

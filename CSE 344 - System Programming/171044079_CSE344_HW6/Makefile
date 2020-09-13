all: pCp

pCp: pCp.o 
	gcc pCp.o  -o pCp -pthread

pCp.o:  pCp.c
	gcc -c  pCp.c 

clear:
	rm *.o
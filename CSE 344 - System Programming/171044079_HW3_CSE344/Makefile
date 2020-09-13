all: gtushell bunedu cat lsf pwd wc 

gtushell: gtushell.o 
	gcc gtushell.o  -o gtushell 
bunedu: buNeDu.o 
	gcc buNeDu.o  -o bunedu 
cat: cat.o 
	gcc cat.o  -o cat
lsf: lsf.o
	gcc lsf.o -o lsf
pwd: pwd.o
	gcc pwd.o -o pwd
wc : wc.o
	gcc wc.o -o wc
gtushell.o:  gtushell.c
	gcc -c  gtushell.c 
buNeDu.o:  buNeDu.c
	gcc -Wall -pedantic-errors -c buNeDu.c 
cat.o:  cat.c
	gcc  -Wall -pedantic-errors -c  cat.c 
lsf.o:  lsf.c
	gcc  -Wall -pedantic-errors -c  lsf.c
pwd.o:  pwd.c
	gcc -ansi -Wall -pedantic-errors -c  pwd.c 
wc.o:  wc.c
	gcc -ansi -Wall -pedantic-errors -c  wc.c


clear:
	rm *.o

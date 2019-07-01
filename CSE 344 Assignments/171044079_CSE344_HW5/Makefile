all: Banka Client

Client: Client.o 
	gcc Client.o  -o Client 

Banka: Banka.o 
	gcc Banka.o  -o Banka -lrt

Client.o:  Client.c
	gcc -c  Client.c 

Banka.o:  Banka.c
	gcc -c Banka.c 

clear:
	rm *.o
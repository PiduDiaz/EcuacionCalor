
BINARY = heat

CFLAGS1 = -O1
CFLAGS2 = -g -O1
LDFLAGS = -lm 


all: heat


heat: tools.o heat.o
	gcc tools.o heat.o -o $(BINARY) $(LDFLAGS)

tools.o: tools.c tools.h
	gcc $(CFLAGS1) -c tools.c $(LDFLAGS)

heat.o: heat.c tools.h
	gcc $(CFLAGS1) -c heat.c $(LDFLAGS)


Debug: tools.o heat.o
	gcc $(CFLAGS2) tools.o heat.o -o $(BINARY) $(LDFLAGS)

clean:
	rm -f $(BINARY) *.o *.txt

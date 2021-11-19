
BINARY = heat

CFLAGS1 = -O1
CFLAGS2 = -g -O1
LDFLAGS = -lm
LAPACKEFLAG = -lblas -llapack -llapacke

all: heat


heat: tools.o heat.o
	gcc tools.o heat.o -o $(BINARY) $(LDFLAGS) $(LAPACKEFLAG)

tools.o: tools.c tools.h
	gcc $(CFLAGS1) -c tools.c $(LDFLAGS) $(LAPACKEFLAG)

heat.o: heat.c tools.h
	gcc $(CFLAGS1) -c heat.c $(LDFLAGS) $(LAPACKEFLAG)


Debug: tools.o heat.o
	gcc $(CFLAGS2) tools.o heat.o -o $(BINARY) $(LDFLAGS) $(LAPACKEFLAG)

clean:
	rm -f $(BINARY) *.o *.txt

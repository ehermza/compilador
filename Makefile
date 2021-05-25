LDLIBS=-lpthread
CFLAGS=-g -Wall
TARGETS=servidor

servidor:	add_tken.o funcion.h getfrom_m.o init_buf.o lexico.o main.o podar.o resolver.o sintaxis.o traslado.o struct.h 
		$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

clean:
		rm -f *.o $(TARGETS)


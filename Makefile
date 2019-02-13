CC=gcc
CFLAGS=-c
LDGLAGS=
OBJS= funciones.o main.o
SOURCES=$(OBJS:.o=.c)
HEADERS=funciones.h
EXE=ej17-9
MAKEFILE=Makefile

$(EXE): $(OBJS)
	@echo "### Generando el ejecutable"
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.c $(MAKEFILE) $(HEADERS)
	@echo "### Compilando " $<
	$(CC) $(CFLAGS) $< -o $@

clean:
	@echo "### Borrando todo"
	rm $(OBJS)
	rm $(EXE)

all: clean $(EXE)




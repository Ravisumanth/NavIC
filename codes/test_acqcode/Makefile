IDIR =./include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =./lib

LIBS=-lm

_DEPS = snr_test.h acq_code.h noise.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_SRC = snr_test.c acq_code.c noise.c
SRC = $(patsubst %,src/%,$(_SRC))

_OBJ = $(_SRC:.c=.o) 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

snr_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# .PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
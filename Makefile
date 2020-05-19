CC = gcc
CFLAGS = -Wall

#Dependencies
DEPS = algor.h dformat.h functions.h

#Object Files
OBJ_ALGOR = functions.o main.o

#Default goal
algor: $(OBJ_ALGOR)
	$(CC) $(CFLAGS) -o $@ $^

#Header dependencies
$(OBJ_ALGOR): $(DEPS)

.PHONY: clean
clean:
	@rm -f *.o *.out *.bin *.txt *.dat *.quest *.ans algor

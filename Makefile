CC = gcc
CFLAGS = -Wall

#Dependencies
DEPS_0 = algor.h dformat.h functions.h
DEPS_1 = dformat.h functions.h
DEPS_2 = functions.h

#Object Files
OBJ_0 = main.o
OBJ_1 = functions.o

#Default goal
algor: $(OBJ_1) $(OBJ_0)
	$(CC) $(CFLAGS) -o $@ $^

#Header dependencies
$(OBJ_0): $(DEPS_0)
$(OBJ_1): $(DEPS_2)

.PHONY: clean
clean:
	@rm -f *.o *.out *.bin *.txt *.dat *.quest *.ans algor

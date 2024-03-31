CC = gcc



all: main

main: functions.o header.h
    $(CC)  -o main main.c functions.o
CC = gcc



all: main

main: functions.o
    $(CC)  -o main main.c functions.o

functions.o: functions.c header.h
    $(CC)  -c functions.c

clean:
    rm -f *.o main

.PHONY: all clean

functions.o: functions.c header.h
    $(CC)  -c functions.c

clean:
    rm -f *.o main  # Remove object files and executable

.PHONY: all clean

#Martynas Lukosevicius
#Makefile Used to contain commands to compile projects

CC=g++
CFLAGS= -std=c++11 -pthread

/** This rule says that each .o file depends on a .cpp file of the same name
*/
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: main.o Semaphore.o
	$(CC) -o mutex main.o Semaphore.o $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

/** this is customary and just deletes all .o files */
CLEAN:
	rm *.o

CC = g++

fraccion: fc.o pila.o
	$(CC) -o fraccion fc.o pila.o

fc.o: fc.cpp
	$(CC) -c fc.cpp

pila.o: pila.cpp
	$(CC) -c pila.cpp

.PHONY: clean
clean:
	$(RM) *.o
# %.o: %.cpp
# $(CC) -c $<

author = Yang Kefan
objects = main.o fraction.o
app = test.out
cc = g++
std = c++0x
app: $(objects)
	$(cc) -std=$(std) $(objects) -o $(app)
main.o: main.cpp fraction.h
	$(cc) -std=$(std) -c main.cpp
fraction.o: fraction.cpp fraction.h
	$(cc) -std=$(std) -c fraction.cpp
.PHONY:
clean:
	rm $(app) *.o

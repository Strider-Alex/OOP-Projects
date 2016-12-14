author = Yang Kefan
cc = g++
std = c++0x
database = diaries.db
app = pdadd pdlist pdremove pdshow
all: $(app)
pdadd: pdadd.cpp diary.h diary.o
	$(cc) -std=$(std) pdadd.cpp diary.o -o pdadd
pdlist: pdlist.cpp diary.h diary.o
	$(cc) -std=$(std) pdlist.cpp diary.o -o pdlist
pdremove: pdremove.cpp diary.h diary.o
	$(cc) -std=$(std) pdremove.cpp diary.o -o pdremove
pdshow: pdshow.cpp diary.h diary.o
	$(cc) -std=$(std) pdshow.cpp diary.o -o pdshow
diary.o: diary.cpp diary.h
	$(cc) -std=$(std) -c diary.cpp
.PHONY: clean
clean:
	rm $(app) *.o
	rm $(database)

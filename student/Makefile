author = Yang Kefan
objects = main.o student.o student_record.o
cc = g++
app: $(objects)
	$(cc) $(objects) -o app
main.o: main.cpp student.h student_record.h
	$(cc) -c main.cpp
student.o: student.cpp student.h
	$(cc) -c student.cpp
student_record.o: student_record.cpp student.h student_record.h
	$(cc) -c student_record.cpp
clean:
	rm app *.o

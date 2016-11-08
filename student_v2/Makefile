author = Yang Kefan
objects = main.o student.o course.o student_record.o
cc = g++
app: $(objects)
	$(cc) $(objects) -o app
main.o: main.cpp student.h course.h student_record.h
	$(cc) -c main.cpp
student.o: student.cpp student.h
	$(cc) -c student.cpp
course.o: course.cpp course.h
	$(cc) -c course.cpp
student_record.o: student_record.cpp student.h student_record.h
	$(cc) -c student_record.cpp
clean:
	rm app *.o

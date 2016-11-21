all: test

test: Course.o Person.o Student.o TeachingAst.o ResearchAst.o GradStudent.o UGradStudent.o Department.o Teacher.o main.o
		g++ -std=c++11 -o test Course.o Person.o Student.o TeachingAst.o ResearchAst.o GradStudent.o UGradStudent.o Department.o Teacher.o main.o

main.o: Course.h Person.h Student.h TeachingAst.h ResearchAst.h GradStudent.h UGradStudent.h Department.h Teacher.h main.cpp
		g++ -std=c++11 -c main.cpp

Course.o: Student.h Teacher.h TeachingAst.h Course.h Course.cpp
		g++ -std=c++11 -c Course.cpp

TeachingAst.o: GradStudent.h TeachingAst.h TeachingAst.cpp
		g++ -std=c++11 -c TeachingAst.cpp

ResearchAst.o: GradStudent.h ResearchAst.h ResearchAst.cpp
		g++ -std=c++11 -c ResearchAst.cpp

GradStudent.o: Student.h GradStudent.h GradStudent.cpp
		g++ -std=c++11 -c GradStudent.cpp

UGradStudent.o: Student.h UGradStudent.h UGradStudent.cpp
		g++ -std=c++11 -c UGradStudent.cpp

Teacher.o: Person.h Teacher.h Teacher.cpp
		g++ -std=c++11 -c Teacher.cpp

Student.o: Person.h Student.h Student.cpp
		g++ -std=c++11 -c Student.cpp

Department.o: Department.cpp Department.h Person.h
		g++ -std=c++11 -c Department.cpp

Person.o: Person.h Person.cpp
		g++ -std=c++11 -c Person.cpp

clean:
		rm *.o

clear:
		rm *.o test

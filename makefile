all: test

test: Course.o Person.o Student.o TeachingAst.o ResearchAst.o GradStudent.o UGradStudent.o Department.o Teacher.o main.o
		g++ -o test Course.o Person.o Student.o TeachingAst.o ResearchAst.o GradStudent.o UGradStudent.o Department.o Teacher.o main.o

main.o: Course.h Person.h Student.h TeachingAst.h ResearchAst.h GradStudent.h UGradStudent.h Department.h Teacher.h main.cpp
		g++ -c main.cpp

Course.o: Student.h Teacher.h TeachingAst.h Course.h Course.cpp
		g++ -c Course.cpp

TeachingAst.o: GradStudent.h TeachingAst.h TeachingAst.cpp
		g++ -c TeachingAst.cpp

ResearchAst.o: GradStudent.h ResearchAst.h ResearchAst.cpp
		g++ -c ResearchAst.cpp

GradStudent.o: Student.h GradStudent.h GradStudent.cpp
		g++ -c GradStudent.cpp

UGradStudent.o: Student.h UGradStudent.h UGradStudent.cpp
		g++ -c UGradStudent.cpp

Teacher.o: Person.h Teacher.h Teacher.cpp
		g++ -c Teacher.cpp

Student.o: Person.h Student.h Student.cpp
		g++ -c Student.cpp

Department.o: Department.cpp Department.h Person.h
		g++ -c Department.cpp

Person.o: Person.h Person.cpp
		g++ -c Person.cpp

clean:
		rm *.o

clear:
		rm *.o test

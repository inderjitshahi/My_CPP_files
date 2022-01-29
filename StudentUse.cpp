#include <iostream>
#include <cstring>
using namespace std;
#include "student.cpp"


int main() {

char name[]="pagal";
	Student s1(name,16);
	s1.display();
	name[2]='A';
	Student s2(name,1002);
	s2.display();
	s1.display();

/*	Student s1;
	s1.age=10;
	s1.roll=101;
	cout << "Address of s1 : " << &s1 << endl;
	s1.display();

	Student *s6= new Student; //dynamic allocation
	(*s6).age=34;			  
	s6 ->roll=104;
	s6->display();
	(*s6).display();*/

	/*
	Student s1;

	s1.display();

	Student s2;

	Student *s3 = new Student;
	s3 -> display();


	cout << "Parametrized constructors Demo" << endl;
	Student s4(10);

	s4.display();

	Student *s5 = new Student(101);
	s5 -> display();

	Student s6(20, 1002);
	s6.display()
	*/
	
}


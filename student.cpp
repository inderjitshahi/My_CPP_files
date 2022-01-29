
class Student{
public:
char *name;
int age;

Student(char *name,int age){
    this->age=age;
   // this->name=name; 
   this->name=new char[strlen(name)+1];
   strcpy(this->name ,name);
}
void display(){
    cout<<name<<" "<<age<<endl;
}

/*
Student(){
    cout<<"ConstructorRuns"<<endl;
}
void set(int r,int a){
    roll=r;
    age=a;
}
void display(){
    cout<<age<<" "<<roll<<endl;
}
*/

};
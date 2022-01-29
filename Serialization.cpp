#include<iostream>
#include<fstream>
using namespace std;
// class student{
//     public:
//    string name; int roll;string branch; 
//    friend ofstream & operator<<(ofstream &ofs,student &s);
//    friend ifstream & operator>>(ofstream &ofs,student &s);
// };
// ofstream & operator<<(ofstream &ofs,student &s){
//     ofs<<s.name<<s.roll<<s.branch;
//     return ofs;
// }
// ifstream & operator >>(ifstream &ifs,student &s){
//     ifs>>s.name>>s.roll>>s.branch;
   
//     return ifs;
// }
int main(){
// student s1;
// s1.name="Inderjit Shahi";
// s1.branch="MCE";
// s1.roll=45;
// ofstream of("My.txt");
// // of<<s1.name<<endl<<s1.roll<<endl<<s1.branch<<endl;
// of<<s1;  //Require Overloading
// of.close();
// ifstream f;
// f.open("My.txt");
// f>>s1;
// cout<<s1.name<<endl;
// cout<<s1.roll<<endl;
// cout<<s1.branch<<endl;
// f.close();
// cout<<scientific<<123.44;
const int a=10;
int A[5]={1,3,4,6,7};
int *p=A;
// cout<<*p;
int *q=&A[4];
cout<<q-p;
return 0;
}
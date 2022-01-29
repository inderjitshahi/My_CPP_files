#include<iostream>

using namespace std;

class Node{
   public:
   int data;
   Node *next;

}*third=NULL;         //global object of Node

void create(Node *p,int C[],int n){    //Creating linked list from array data
   int i;
   Node *t,*last;
   p=new Node;
   p->data=C[0];
   last=p;
   for ( i = 1; i < n; i++)
   {
      t=new Node;
      t->data=C[i];
      t->next=NULL;
      last->next=t;
      last=t;
   }
}



void display(Node *z){
   Node *p=z;
   while (p!=0)
   {
      cout<<p->data<<"\t";
      p=p->next;
   }
   
}







void Isort(Node *first,Node *second){
   Node *ptr=first;
   Node *link=second;
   // Node *last;
   while(ptr!=0&&link!=0){
         Node *temp=ptr->next; 
         ptr->next=link->next; 
         link->next=temp;
         ptr=ptr->next;
         link=link->next;
   
   }

}

int main(){           //driving function

Node *first=NULL;
Node *second=NULL;
 int A[]={4,5,7,9,10,15};
 int B[]={1,3,8,11,12,13};
 create(first,A,6);
 create(second,B,6);
//  cout<<"\n";
 display(first);
//   cout<<"\n";
//  display(second);
//  cout<<"\n";
//  Isort(first,second);
//  cout<<"\n";
//  display(first);
//   cout<<"\n";
//  display(second);
//  cout<<"\n";
 
   return 0;

}
#include<iostream>

using namespace std;

class Node{
   public:
   int data;
   Node *next;

}*first=NULL,*second=NULL,*third=NULL;         //global object of Node

void create(int A[],int n){    //Creating linked list from array data
   int i;
   Node *t,*last;
   first=new Node;
   first->data=A[0];
   last=first;
   for ( i = 1; i < n; i++)
   {
      t=new Node;
      t->data=A[i];
      t->next=NULL;
      last->next=t;
      last=t;
   }
}

void create2(int A[],int n)
{                            //Creating linked list from array data
   int i;
   Node *t,*last;
   second=new Node;
   second->data=A[0];
   last=second;
   for ( i = 1; i < n; i++)
   {
      t=new Node;
      t->data=A[i];
      t->next=NULL;
      last->next=t;
      last=t;
   }
}

void display(Node *z){
   Node *p=z;
   while (p!=0)
   {
      cout<<p->data<<endl;
      p=p->next;
   }
   
}







void Isort(Node *first,Node *second){
   Node *p=first;
   Node *q=second;
   Node *last;
   if (p->data > q->data)
   {
      third =last=q;
      q=q->next;
      third->next=0;
   }
   else
   {
      third =last=p;
      p=p->next;
      third->next=0;
   }
   
   while (p && q)
   {
     if (p->data > q->data)
     {
        last->next=q;
        last=q;
        q=q->next;
        last->next=0;
     }
     else
     {
        last->next=p;
        last=p;
        p=p->next;
        last->next=0;
     }  
   }
   
   while (p!=0)
   {
     last->next=p;
        last=p;
        p=p->next;
        last->next=0;
   }
   while (q!=0)
   {
     last->next=q;
        last=q;
        q=q->next;
        last->next=0;
   }
   
}

int main(){           //driving function
 int A[]={4,5,7,9,10,15};
 int B[]={1,3,8,11,12,13};
 create(A,6);
 create2(B,6);
 Isort(first,second);
 display(third);
 
   return 0;

}
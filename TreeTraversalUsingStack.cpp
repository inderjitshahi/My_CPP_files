// 20-05-2021 by Inddrjit Shahi
#include<iostream>
#include<cstring>
#include<math.h>
#include<iomanip> //for setprecision

using namespace std;
struct Node
{   
    Node *lchild,*rchild;
    int data;
}*root=NULL;

struct queue{
    int f,r,size;
    Node **Q; // to store the address of node pointer eg:- *root.
};
struct stack{
    int top,size;
    Node **S; 
};
void enqueue(queue *q,Node* x){
    if ((q->r+1)%q->size==q->f)
        cout<<"queue is full"<<endl;
    else{
        q->r=(q->r+1)%q->size;
        q->Q[q->r]=x;
    }   
    
}
Node*  dequeue(queue *q){
    Node *x=0;
    if((q->f==q->r)) cout<<"queue is empty"<<endl;
    else{
        q->f=(q->f+1)%q->size;
        x=q->Q[q->f];
    }
    return x;
}
int isEmpty(queue p){
    return p.f==p.r;
}

void Treecreate(queue q){
    Node *p,*t;
    int x;
    cout<<"enter the root value : ";
    cin>>x;
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=0;
    enqueue(&q,root);

    while(!isEmpty(q)){
        p=dequeue(&q);
        cout<<"enter left child: ";
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x; t->lchild=t->rchild=0;
            p->lchild=t;
            enqueue(&q,t);
        }
        cout<<"enter reght child: ";
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x; t->lchild=t->rchild=0;
            p->rchild=t;
            enqueue(&q,t);
        }
    }

}
void preoder(Node *p){
    if(p){
        cout<<p->data<<endl;
        preoder(p->lchild);
        preoder(p->rchild);
    }
}
int isEmpty(stack st){
    int x=0;
    if(st.top==st.size-1) x=1;
    return x;
}
void push(stack* st,Node* t){
    if(st->top==st->size-1) return;
    else{
        st->top+=1;
        st->S[st->top]=t;
    }   
}
Node* pop(stack* st){
    Node* x=0;
    if(st->top==-1) return x;
    else {
        x=st->S[st->top];
        st->top=st->top-1;
    }
    return x;
}
void Itpreorder(Node *t,stack st){
    while(t!=0||!isEmpty(st)){
        if (t!=NULL)
        {
           cout<<t->data<<endl;
           push(&st,t);
           t=t->lchild;
        }
        else{
            t=pop(&st);
            t=t->rchild;
        }
        

    }
}


int main(){
    queue q;
  q.size=100;
  q.f=q.r=-1;
  q.Q=new Node*[q.size]; //Node* because to store address of nodes
   Treecreate(q) ;
  stack st;
  st.size=100;
  st.top=-1;
  st.S=new Node*[st.size];
  preoder(root);
  Itpreorder(root,st);

 return 0;  
}
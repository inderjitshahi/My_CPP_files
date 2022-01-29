#include<iostream>
#include<cstring>
#include<math.h>
#include<iomanip>

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
    Node *root=new Node;
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
void Inoder(Node *p){
    if(p){
        Inoder(p->lchild);
        cout<<p->data<<endl;
        Inoder(p->rchild);
    }
}

int main(){
    queue q;
  q.size=100;
  q.f=q.r=-1;
  q.Q=new Node*[q.size];
   Treecreate(q) ;
   preoder(root);

 return 0;  
}
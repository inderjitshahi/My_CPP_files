#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
} * first;
void create(node *first)
{
    node *last;
    last = first;
    int n, data = 0;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "enetr the data of " << 1 << "st node: ";
    cin >> data;
    last->data = data;
    last->next = NULL;

    for (int i = 1; i < n; i++)
    {
        cout << "enetr the data of node " << i + 1 << " :";
        cin >> data;
        node *t = new node;
        t->data = data;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void insert(node *first,int n){
  node *t=new node;
  node *p=first;
  cout<<"enetr data of the node";
  cin>>t->data;
//   t->next=0;
 for (int i = 0; i < n-1; i++)
 {
     p=p->next;
 }
 t->next=p->next;
 p->next=t;
  
}
void display(node *first)
{
    node *p = new node;
    p = first;
    while (p != 0)
    {
        cout << p->data << "\t";
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    first = new node;
    create(first);
    display(first);
    insert(first,3);
    display(first);
    return 0;
}
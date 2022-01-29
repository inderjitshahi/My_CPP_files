#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
class Hash{
    public:
    node **HT;//a pointer for storing head pointers of the all lists
    Hash();
    int hash(int key); //hash function,returning index
    void insert(int key);
    int search(int key);
    ~Hash();
};
Hash::Hash()
{
    HT=new node*[10];
    for (int i = 0; i < 10; i++) HT[i]=nullptr; //initializing all head pointer to null  
}

int Hash::hash(int key){
    return key%10; // calculating index
}
void Hash::insert(int key)
{
    int index=hash(key);
    node *t=new node;
    t->data=key;
    t->next=0;
    if(HT[index]==0) {HT[index]=t;}
    else{
        node *p=HT[index];
        node* q=p;
        while(p&& p->data<key){
            q=p; p=p->next;
        }
        if(q==HT[index]){t->next=HT[index];HT[index]=t;}
        else{t->next=q->next;q->next=t;}
    }

}
int Hash::search(int key)
{
    int index=hash(key);
    node *p=HT[index];
    while(p){
        if(p->data==key){return p->data;}
        p=p->next;
    }
    return -1;
}
Hash::~Hash(){
    for (int i = 0; i < 10; i++)
    {
        node* p=HT[i];  //deletint every head node
        while(HT[i]){
            HT[i]=HT[i]->next;
            delete p;
            p=HT[i];
        }
    }
    delete [] HT;
}

int main()
{
    int A[]={12,46,23,45,565,52,11,333,44,47,112,445};
    int n=sizeof(A)/sizeof(A[0]);
    Hash H; // object for hash class
    for (int i = 0; i < n; i++)
    {
        H.insert(A[0]);
    }
    cout << "Successful Search" << endl;
	int key = 12;
	int value = H.search(key);
	cout << "Key: " << key << ", Value: " << value << endl;
	cout << "Unsuccessful Search" << endl;
	key = 95;
	value = H.search(key);
	cout << "Key: " << key << ", Value: " << value << endl;

	
    return 0;
}
#include<iostream>
using namespace std;

class matrix{
    private:
       int A[10];
    int n;
    public:
    matrix(int n){
        this->n=n;
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display(matrix m){
        int i,j;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
               if(i==j) cout<<m.A[i]<<" ";
               else cout<<0<<" ";
            }
            cout<<endl;
            
        }
        
    }
    // ~matrix();
};
void matrix::set(int i,int j,int x){
    if(i==j) A[i-1]=x; 
}
int matrix::get(int i,int j){ //Accessing values of matrix
    if(i==j) return A[i-1]; 
    else return 0;
}
int main(){
matrix m(4);
// m.n=4;
m.set(1,1,5);
m.set(2,2,9);
m.set(3,3,20);
m.set(4,4,13);
// cout<<m.get(m,1,1);
m.display(m);


return 0;
}
#include<iostream>
#include<cstring>

using namespace std;
struct stack{
    int top,size;
    char *s;
};

void push(stack *st,char x){
    if(st->top==st->size-1)
    cout<<"stack overflow";
    else{
        st->top++;
        st->s[st->top]=x;
    }
}

int pop(stack *st){
    int x=-1; 
    if (st->top==-1)
     cout<<"stack underflow";
    else{
    x=st->s[st->top];
    st->top--; 
    }
    return x;
}
 
int peek(stack st,int index){
    char x=-1;
    if (st.top-index+1<0)
    return x;
    else{
        x=st.s[st.top];
    }
    
  return x;  
} 
int isMatching(char exp[]){
    stack st;
    st.size=strlen(exp);
    st.top=-1;
    st.s=new char[st.size];
    char x;
    bool a=false;


  for (int i = 0;exp[i] !='\0'; i++)
  {
      if(exp[i]=='('||exp[i]=='['||exp[i]=='{')
      push(&st,exp[i]);
      else if(exp[i]==')'||exp[i]==']'||exp[i]=='}'){
           if(st.top==-1) return 0;
            x=pop(&st);
            if(exp[i]==')'&&x=='('||exp[i]==']'&&x=='['||exp[i]=='}'&&x=='{'){}
           
            else return 0;
       }
  }
  if(st.top==-1)
  return 1;
  else 
  return 0;
  
}
int main(){
    
    
   char exp[]="{([a+b]*[c-g]/e)}";
   cout<<isMatching(exp);
}
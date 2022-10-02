#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int size;
    int top;
    int *s;
};
int stacktop(Stack st)
{
    if(st.top==-1)
    return -1;
    else 
    return st.s[st.top];
}
int isempty(Stack st)
{
    if(st.top==-1)
    return 1;
    else 
    return 0;
}
int isfull(Stack st)
{
    if(st.top==st.size-1)
    return 1;
    else 
    return 0;
}
void push(Stack *st,int x)
{
    if(st->top==st->size-1)
    cout<<"Stack is overflow";
    else 
    {
        st->top++;
        st->s[st->top]=x;
    }
}
int pop(Stack *st)
{int x=-1;
if(st->top==-1)
cout<<"Stack is underflow";
else
{
    x=st->s[st->top];
    st->top--;
}
return x;
}
int peek(Stack st,int index)
{
    int x=-1;
    if(st.top-index+1<0)
    cout<<"Invalid Index";
    else
    x=st.s[st.top-index+1];
    return x;
}
void create(Stack *st)
{cout<<"Enter size ";
 int n;
 cin>>n;
 st->size=n;
  st->s=new int[n];
//  st->s=(int *)malloc(st->size*sizeof(int));
st->top=-1;

}
void display(Stack st)
{for(int i=st.top;i>=0;i--)
cout<<st.s[i]<<endl;   
}
int main(){
   struct Stack st;
    create(&st);
 push(&st,35);
 push(&st,40);
 push(&st,45);
 push(&st,20);
 cout<<pop(&st);
 cout<<"Peek value with index x:"<<" ";
 int x;cin>>x;
cout<<"The value is:";
 cout<<peek(st,x)<<endl;
 display(st);
    return 0;
}
// code in c
/*
 
#include <stdio.h>
#include <stdlib.h>
struct Stack
{
 int size;
 int top;
 int *S;
};
void create(struct Stack *st)
{
 printf("Enter Size");
 scanf("%d",&st->size);
 st->top=-1;
 st->S=(int *)malloc(st->size*sizeof(int));
}
void Display(struct Stack st)
{
 int i;
 for(i=st.top;i>=0;i--)
 printf("%d ",st.S[i]);
 printf("\n");
 
}
void push(struct Stack *st,int x)
{
 if(st->top==st->size-1)
 printf("Stack overflow\n");
 else
 {
 st->top++;
 st->S[st->top]=x;
 }
 }
int pop(struct Stack *st)
{
 int x=-1;
 
 if(st->top==-1)
 printf("Stack Underflow\n");
 else
 {
 x=st->S[st->top--];
 }
 return x;
}
int peek(struct Stack st,int index)
{
 int x=-1;
 if(st.top-index+1<0)
 printf("Invalid Index \n");
 x=st.S[st.top-index+1];
 
 return x;
}
int isEmpty(struct Stack st)
{
 if(st.top==-1)
 return 1;
 return 0;
}
int isFull(struct Stack st)
{
 return st.top==st.size-1;
}
int stackTop(struct Stack st)
{
 if(!isEmpty(st)) return st.S[st.top];
 return -1;
}
int main()
{
 struct Stack st;
 create(&st);
 
 push(&st,10);
 push(&st,20);
 push(&st,30);
 push(&st,40);
 
 printf("%d \n",peek(st,2));
 
 
 Display(st);
 
 return 0;
}
*/
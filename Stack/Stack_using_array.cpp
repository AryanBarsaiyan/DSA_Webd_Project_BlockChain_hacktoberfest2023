#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
    int size;
    int top;
    int *arr;
};
int isempty(class Stack *pt)
{
    if(pt->top==-1)
    return 1;
    else
    return 0;
}
int isfull(class Stack *pt)
{
    if(pt->top==ptr->size-1)
   return 1;
   else
   return 0;
}
void push(class Stack *s,int x)
{
    if(s->top==s->size-1)
    cout<<"Stack is full"<<endl;
    else
    s->top++;
    s[s->top]=x;
}
void display()
{
     for(int i=s->top;i>=0;i--)
    cout<<s[i]<<" ";
}
int main(){
class Stack *s;
s->size=10;
s->top=-1;
s->arr=new int[size];
for(int i=0;i<5;i++)
{
    cin>>arr[i];
    s.push(&s,arr[i]);
}
s.display();
return 0;
}
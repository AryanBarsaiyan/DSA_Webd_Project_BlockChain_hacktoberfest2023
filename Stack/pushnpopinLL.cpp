//Push and pop on stack
#include <iostream>
using namespace std;
//USING C++ CLASS
/*class Node{
    public:
    int data;
    Node *next;
};
class Stack{
    private:
    Node *top;
    public:
    Stack()
    {top=NULL};
    void push(int x);
    int pop();
    void Display();
}
void Stack::push(int x)
{
    struct Node *t;
    t=new Node;
    if(t==NULL)
    cout<<"Stack is full";
    else 
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

*/
struct Node{
    int data;
    Node *next;
}*top=NULL;
void push(int x)
{
    struct Node *t;
    t=new Node;
    if(t==NULL)
    cout<<"Stack is full";
    else 
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}
int pop()
{struct Node *t;
t=top;
int x=-1;
if(top==NULL)
cout<<"Stack is Empty";
else
{
    t=top;
    top=top->next;
    x=t->data;
    delete t;
}
return x;
}
void Display()
{
    struct Node *p;
    p=top;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{ push(35);
 push(40);
 push(50);
 pop();
 Display();
    

    return 0;
}
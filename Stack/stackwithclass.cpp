#include <bits/stdc++.h>
using namespace std;
template<class T>
class Stack{
    private:
      T *stk;
      int top;
      int size;

    public:
    Stack(int sz)
    {
        size=sz;
        top=-1;
        stk=new int[size];

    }
    void push(T x);
    T pop();
    void Display();

};
template<class T>
void Stack<T>::push(T x)
{
    if(top==size-1)
    {
        cout<<"Stack is full"<<endl;

    }
    else{
        top++;
        stk[top]=x;
    }
}
template<class T>
T Stack<T>::pop()
{
    T x=0;
    if(top==-1)
    cout<<"Stack is empty"<<endl;
    else
    {
        x=stk[top];
        top--;

    }
    return x;

}
template<class T>
void Stack<T>::Display()
{
    for(int i=top;i>=0;i--)
    cout<<stk[i]<<" ";
}
int main()
{
    Stack<int> s(10);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(50);
    s.pop();
    s.push(40);
    s.Display();
return 0;
}
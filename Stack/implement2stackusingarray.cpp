#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;
class Stacks{
   
    int size;
    int top1,top2;
    int *arr;
    public:
    Stacks(int n)
    {
        size=n;
        arr=new int[n];
        top1=-1;
        top2=size;
    }
    void push1(int x)
    {
        if(top1<top2-1)
        {
            top1++;
            arr[top1]=x;
            
         }
         else
         cout<<"Stack is full"<<endl;
    }
    void push2(int x)
    {
        if(top1<top2-1)
        {
            top2--;
            arr[top2]=x;
        }
        else
        cout<<"Stack is full"<<endl;
    }
    int pop1()
    { int x=-1;
        if(top1>=0)
        {
             x=arr[top1];
            top1--;
           
        }
        else
        cout<<"Stack is empty"<<endl;
         return x;
    }
    int pop2()
    { int x=-1;
        if(top2<size)
        {
             x=arr[top2];
            top2++;
           
        }
        else
        cout<<"Stack is empty"<<endl;
         return x;
    }
};

int main(){
class Stacks s(10);
s.push1(5);
s.push1(51);
s.push1(1);
s.push1(13);
s.push2(10);
s.push2(15);
s.push2(46);
s.push2(53);
cout<<"element pop from stack 1 :"<<s.pop1()<<endl;
cout<<"element pop from stack 2 :"<<s.pop2()<<endl;
return 0;
}
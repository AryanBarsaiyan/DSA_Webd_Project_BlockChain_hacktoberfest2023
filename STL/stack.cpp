#include<iostream>
#include<stack>

using namespace std;

int main(){

    stack<string> s;

    s.push("Aman");
    s.push("Kumar");
    s.push("Poddar");

    cout<<"Top element in stack:- "<< s.top()<<endl;
    s.pop();
    cout<<"Top element in stack:- "<< s.top()<<endl;

    cout<<"Size of stack:- "<<s.size()<<endl;

    cout<<"Empty or not:- "<<s.empty()<<endl;

}
#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<string> q;
    q.push("Aman");
    q.push("Kumar");
    q.push("Poddar");

    cout<<"First Element:- "<<q.front()<<endl;
    q.pop();
    cout<<"First Element After pop:- "<<q.front()<<endl;

    cout<<"Size after pop:- "<<q.size()<<endl;
}
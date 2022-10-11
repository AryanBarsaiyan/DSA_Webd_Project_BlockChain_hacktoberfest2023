#include<iostream>
#include<deque>

using namespace std;

int main(){
    deque <int> d;

    d.push_back(1);
    d.push_front(2);


    cout<<"Print First index element"<<d.at(1)<<endl;

    cout<< "front:- " <<d.front()<<endl;
    cout<<"back:- "<<d.back()<<endl;

    cout<<"Empty or not:- "<<d.empty()<<endl;

    cout<<"Before Erase size is:- "<<d.size()<<endl;
    d.erase(d.begin() , d.begin()+1);
    cout<<"After Erase size is:- "<<d.size()<<endl;

    for(int i : d){
        cout<<i<<endl;
    }

}
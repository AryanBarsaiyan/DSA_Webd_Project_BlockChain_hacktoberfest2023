#include<iostream>
#include<queue>

using namespace std;

int main() {

//max_heap
priority_queue<int> maxi;
maxi.push(1);
maxi.push(3);
maxi.push(0);
maxi.push(2);

int n = maxi.size();
for(int i=0;i<n;i++){
    cout<<maxi.top()<<" ";
    maxi.pop();
}

cout<<endl;
cout<<"Empty?? :- "<<maxi.empty()<<endl;
//min_heap
priority_queue<int , vector<int> , greater<int> > mini;

mini.push(5);
mini.push(3);
mini.push(1);
mini.push(2);

int k = mini.size();
for(int i=0;i<k;i++){
    cout<<mini.top()<<" ";
    mini.pop();
}

cout<<endl;


cout<<"Empty??:-"<<mini.empty()<<endl;

}
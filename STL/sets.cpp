#include<iostream>
#include<set>

using namespace std;

int main(){

set<int> s;

s.insert(7);
s.insert(7);
s.insert(7);
s.insert(9);
s.insert(9);
s.insert(1);
s.insert(2);
s.insert(2);
s.insert(0);
s.insert(0);
s.insert(0);

for(auto i : s){
    cout<<i<<endl;
}

cout<<endl;
set<int>::iterator it = s.begin();
it++;

s.erase(it);

for(auto i : s){
    cout<<i<<endl;
}
cout<<endl;
//to check element is present or not
cout<<"9 is present or not? => "<<s.count(9)<<endl;

set<int>::iterator itr = s.find(7);
cout<<"Present value at itr=> "<<*it<<endl;

for(auto it =itr ; it!=s.end(); it++){
    cout<<*it<<" ";

    }
    cout<<endl;

}
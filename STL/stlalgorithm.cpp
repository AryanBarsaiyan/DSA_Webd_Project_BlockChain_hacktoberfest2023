#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
vector<int> v;

v.push_back(1);
v.push_back(3);
v.push_back(6);
v.push_back(7);
v.push_back(9);

cout<<"Finding 6:- "<<binary_search(v.begin() , v.end() , 6 );

cout<<"Lower Bound:- "<<lower_bound(v.begin() , v.end() , 6)-v.begin()<<endl;
cout<<"Upper Bound:- "<<upper_bound(v.begin() , v.end() , 6)-v.begin()<<endl;

int a =3;
int b =7;

cout<<"Max:- "<<max(a , b)<<endl;
cout<<"Min:- "<<min(a , b)<<endl;
swap(a , b);
cout<<" After Swap a:- "<<a<<endl;

string s = "abcd";
reverse(s.begin(), s.end());
cout<<"String:- "<<s<<endl;
}
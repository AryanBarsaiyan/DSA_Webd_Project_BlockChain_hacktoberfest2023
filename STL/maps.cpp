#include<iostream>
#include<map>

using namespace std;

int main(){
     map<int , string> m;

     m[1]= "Poddar";
     m[2]= "aman";
     m[13]= "kumar";

     m.insert({5 , "bheem"});
cout<<"After erase"<<endl;
    for(auto i:m ){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"Finding13-> "<<m.count(13)<<endl;

m.erase(13);
cout<<"After erase"<<endl;

 for(auto i:m ){
        cout<<i.first<<" "<<i.second<<endl;
    }

//time complexity is O(logn) bec made used using red black tree , balanced tree

auto it = m.find(5);

for(auto i = it; i!=m.end(); i++){
    cout<<(*i).first <<endl;
}
}


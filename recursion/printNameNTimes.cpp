#include<bits/stdc++.h>
using namespace std;

void printName(string name , int cnt){
    
    if(cnt == 5)
        return;
    cout<<name<<endl;
    printName(name , ++cnt);
}

int main(){

    string name = "Manogya";
    printName(name , 0);
    return 0;
}
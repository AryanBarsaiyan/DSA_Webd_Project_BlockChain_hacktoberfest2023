#include<iostream>
#include<cmath>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,m;
cout<<"Enter the size of the matrix"<<endl;
cin>>n>>m;
int array[n][m];

for (int i = 0; i < n; i++)
{
    for (int j = 0; j <m; j++)
    {
        cin>>array[i][j];
    }
}
int key;
cout<<"Enter the element to be searched"<<endl;
cin>>key;

for (int i = 0; i < n; i++)
{
    for (int j = 0; j <m; j++)
    {
        if (array[i][j]==key)
        {
            cout<<i+1<<","<<j+1;
        } 
        
    }
}

return 0;
}

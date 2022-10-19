#include<iostream>
#include<cmath>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int array_size;
    cout<<"Enter the array size"<<endl;
    cin>>array_size;
    int array[array_size];
    for (int i = 0; i <array_size; i++)
    {
        cin>>array[i];
    }
    for (int i = 1; i < array_size; i++)
    {
        int key = array[i];
        int j = i-1;

        while (key<array[j]&& j>0)
        {
            array[j+1]= array[j];
            j = j-1;
        }
        j = key;
        cout<<array[i]<<endl;
        
    }
    

return 0;
}

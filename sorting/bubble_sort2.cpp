#include<iostream>
#include<cmath>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int array_size;
    cout<<"Enter the size of the array"<<endl;
    cin>>array_size;
    int array [array_size];
    for (int i = 0; i < array_size; i++)
    {
        cin>>array[i];
    }
    
    int counter = 1;
    while (counter<array_size)
    {
        for (int i = 0; i < array_size-counter; i++)
        {
            if (array[i]>array[i+1])
            {
                int temp  = array[i];
                array[i]= array[i+1];
                array[i+1]= temp;
                
            }
            
        }
       counter++; 
    }
    for (int i = 0; i < array_size; i++)
    {
        cout<<array[i]<<endl;
    }
    


return 0;
}

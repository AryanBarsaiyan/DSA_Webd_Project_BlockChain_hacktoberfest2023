#include <iostream>
using namespace std;

void merge(int * a, int si, int mid , int ei)
 { 

     int  p[100];
     
    int p1,p2;
    p1=si;
    p2= mid+1;
    int i =0;
    while (p1<=mid && p2<= ei)
    {
        if(a[p1]<a[p2])
        {
            p[i++] = a[p1++];
        }
        else 
        {
            p[i] = a[p2++];
            
        }
    }
    while(p1<=mid)
    {
        p[i++]= a[p1++];
    }
    while(p2<=ei)
    {
        p[i++] = a[p2++];
    }
    i=0;
    for(int j=si; j<=ei; j++ )
    {
        a[j]=p[i++];
        
    }

 }
void merge_sort(int a[] , int si , int ei)
{
    if(si >=ei )
    {
        return;
    }
    int mid;
    mid = ((si+ei)/2);
    merge_sort(a, si , mid);
    merge_sort(a, mid+1  , ei);
    
    merge(a , si , mid ,  ei);
  
}

int main()
{
    int i;
    int a[5];
    cout<<"enter array elements"<<endl;
    for( i=0; i<5; i++)
    {
        cin>>a[i];
        }
        merge_sort(a,0,5);
       for ( i = 0; i<=4 ; i++)
    {
        cout<< a[i]<<endl;
    }

    return 0;
}
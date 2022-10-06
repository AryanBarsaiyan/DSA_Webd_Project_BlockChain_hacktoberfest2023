#include<iostream>
using namespace std ;
  
int binary(int ar[],int item ,int size) 
{int beg=0,last= size-1,mid;
while(beg<=last)
{mid=(beg+last)/2;
if(item==ar[mid])
return mid;
else if(item>ar[mid])
beg=mid+1;
else if(item<ar[mid])
last=mid-1;
}
return -1;
}
int main()
{
int s[100],item,index,size;
cout<<"input the size:";
cin>>size;
cout<<"input a sorted array"<<endl;
for(int i=0;i<size;i++)
cin>>s[i];
cout<<"enter the element to be searched:";
cin>>item;
index=binary(s,item,size);
if(index==-1)
cout<<"element not found";
else
cout<<"element found at:"<<index<<",position"<<index+1<<endl;
return 0;

}
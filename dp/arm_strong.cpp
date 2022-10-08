#include <iostream>

using namespace std;

int main()
{
   int n,cube,num,r,sum=0;
   
   cout<<"enter number"<<endl;
   cin>>n;
   num=n;
  while(n!=0){
      r=n%10;
      cube=r*r*r;
      sum=sum+cube;
      n/=10;
  }
  if(sum==num)
   cout<<num<<" is an Armstrong number "<<endl;
   else
   cout<<num<<" is not an armstrong number"<<endl;
   
}
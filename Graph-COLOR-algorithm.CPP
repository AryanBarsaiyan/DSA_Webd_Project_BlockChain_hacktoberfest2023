#include<iostream>
#include<conio.h>
using namespace std;

int i,j,m,n,x[5],g[5][5];
void nextvalue(int k);

void mcoloring(int k)
{
 do
 {
   nextvalue(k);
   if(!x[k])
   break;
   if(k==n)
   {
     for(int i=1;i<=n;i++)
     cout<<x[i]<<' ';
     cout<<endl;
   }
   else
   mcoloring(k+1);
 }
 while(1);
}
 void nextvalue(int k)
 {
   do
   {
     x[k]=(x[k]+1)%(m+1);
     if(!x[k])
     return;
     for(int j=1;j<=k-1;j++)
     {
       if((g[k][j]!=0) && (x[k]==x[j]))
       break;
     }
     if(j==k)
     return;
   }
   while(1);
 }
 int main()
     {
        cout<<"Enter vertext number: ";
       cin>>n;
       cout<<"Enter Color number  : ";
       cin>>m;
       for(i=1;i<=n;i++)
       x[i]=0;
       cout<<"\nEnter edge info\n\n";
       for(i=1;i<n+1;i++)
       {
	 for(j=1;j<n+1;j++)
	 {
	   cout<<"Edge from vertex "<<i<<"To vertex"<<j<<" :";
	   cin>>g[i][j];
	 }
	   cout<<"\n";
       }
       mcoloring(1);
    return 0;
 }

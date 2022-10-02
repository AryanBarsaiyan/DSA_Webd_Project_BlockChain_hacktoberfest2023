
#include <bits/stdc++.h>
using namespace std;
int a[100005],seg[4*100005];
void buildtree(int ind,int low,int high)
{
    if(low==high)
    {
        seg[ind]=a[low];
        return;
    }
    int mid=low+(high-low)/2;
    buildtree(2*ind+1,low,mid);
    buildtree(2*ind+2,mid+1,high);
    seg[ind]=(seg[2*ind+1]+seg[2*ind+2]);
}
int query(int ind,int low,int high,int l,int r)
{
  if(low>r || high<l)
  return 0;
  if(l<=low and high<=r)
  {
    return seg[ind];
  }
  int mid=low+(high-low)/2;
  int left=query(2*ind+1,low,mid,l,r);
  int right=query(2*ind+2,mid+1,high,l,r);
  return left+right;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    buildtree(0,0,n-1);
//    for(int i=0;i<25;i++)
//    {
//     cout<<seg[i]<<" ";
//    }
int q;
cin>>q;
while(q--)
{
  int type;
  cin>>type;
  if(type==1)
  {
    
    int l,r;
    cin>>l>>r;
    cout<<query(0,0,n-1,l,r)<<endl;
  }
 
}    

}
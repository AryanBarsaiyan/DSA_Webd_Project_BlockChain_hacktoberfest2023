//  We have find max value in a subarray with given query 
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
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
}
int query(int ind,int low,int high,int l,int r)
{
 if(low>=l and high<=r)
 {
    return seg[ind];
 }
 if(high<l || low>r)
 return INT_MIN;
 int mid=low+(high-low)/2;
 int left=query(2*ind+1,low,mid,l,r);
 int right=query(2*ind+2,mid+1,high,l,r);
return max(left,right);
}
void update(int node,int low,int high,int idx,int val)
{
  if(low==high)
  {
    a[low]=val;
    seg[node]=val;
    return;
  }
  int mid=low+(high-low)/2;
  if(idx<=mid)
  {
    update(2*node+1,low,mid,idx,val);
  } 
  else 
  {
    update(2*node+2,mid+1,high,idx,val);
  }
  seg[node]=max(seg[2*node+1],seg[2*node+2]);
}
int main()
{ 
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    buildtree(0,0,n-1);
   
    while(1)
    {
        int type;
        cin>>type;
        if(type==-1)
        break;
        if(type==1)
        {
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r)<<endl;
        }
        else if(type==2)
        {
            int idx,val;
            cin>>idx>>val;
            update(0,0,n-1,idx,val); 
            
        }
    }
}
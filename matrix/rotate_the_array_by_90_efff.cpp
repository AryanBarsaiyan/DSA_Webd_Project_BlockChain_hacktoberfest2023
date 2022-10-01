#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void transpose(int **arr,int r,int c)                           //efficient solution
{
    for(int i=0;i<r;i++)
    {
        for(int j=i+1;j<c;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
}
int rotate(int **a,int r,int c)
{
    transpose(a,r,c);
    cout<<"after transpose"<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<setw(4)<<a[i][j]<<"  ";
        cout<<endl;
    }
    for(int i=0;i<r/2;i++)
    {
        for(int j=0;j<c;j++)
        {
            swap(a[i][j],a[r-1-i][j]);
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif  
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int **a;
    int r,c;
    cin>>r>>c;
    int count=0;
    a=new int *[r];
    for(int i=0;i<r;i++)
    {
        a[i]=new int [c];
        for(int j=0;j<c;j++)
            a[i][j]=count++;
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<setw(4)<<a[i][j]<<"  ";
        cout<<endl;
    }
    cout<<endl;
    rotate(a,r,c);
    cout<<"after rotation"<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<setw(4)<<a[i][j]<<"  ";
        cout<<endl;
    }
    
}
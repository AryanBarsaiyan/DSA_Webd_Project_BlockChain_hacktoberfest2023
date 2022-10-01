#include<bits/stdc++.h>
using namespace std;
void boundary_element(int **arr,int R,int C)
{
    cout<<"Boundary Element ->"<<endl;
    for(int i=0;i<R;i++)
    {
        if(i==0 || i==R-1)
        {
            for(int j=0;j<C;j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }
        else
        {
            for(int j=0;j<C;j++)
            {
                if(j==0 || j==C-1)
                    cout<<arr[i][j]<<" ";
                else
                    cout<<"  ";
            }
            cout<<endl;
        }
    }
}
int main()
{
    int **a;
    int R,C;
    cin>>R>>C;
    a=new int *[R];
    for(int i=0;i<R;i++)
    {
        a[i]=new int [C];
    }
    int count=0;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            a[i][j]=count++;
            cout<<a[i][j]<<"  ";
        }
        cout<<endl;
    }
    boundary_element(a,R,C);
}
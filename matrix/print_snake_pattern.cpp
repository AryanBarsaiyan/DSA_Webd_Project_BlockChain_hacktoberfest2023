#include<bits/stdc++.h>
using namespace std;
void snake_pattern(int **arr,int R,int C)
{
    cout<<"Snake Pattern ->"<<endl;
    for(int i=0;i<R;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<C;j++)
            {
                cout<<arr[i][j]<<"  ";
            }
        }
        else
        {
            for(int j=C-1;j>=0;j--)
            {
                cout<<arr[i][j]<<"  ";
            }
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
    snake_pattern(a,R,C);
}
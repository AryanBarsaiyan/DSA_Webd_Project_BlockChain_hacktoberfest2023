#include<bits/stdc++.h>
using namespace std;
void rotate(int arr[3][3])
{
    int temp[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            temp[3-j-1][i]=arr[i][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            arr[i][j]=temp[i][j];
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[3][3];
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=count++;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    rotate(arr);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
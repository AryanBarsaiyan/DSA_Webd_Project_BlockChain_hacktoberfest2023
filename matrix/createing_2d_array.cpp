#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int m=3,n=2;
    // int arr[m][n]={{10,20},{30,40},{50,60}};                                // method 1
    // for(int i=0;i<m;i++)
    //     for(int j=0;j<n;j++)
    //         cout<<arr[i][j]<<"   ";s
    //         cout<<endl;
    // int arr[m][n]={10,20,30,40,50,60};                                        //some error only print 10 and 20
    // for(int i=0;i<m;i++)
    //     for(int j=0;j<n;j++)
    //         cout<<arr[i][j]<<"   ";
    //         // cout<<endl;                                                  //method 2;


    // int arr[3][2]={10,20,30,40,50,60};                                        // runs perfectly
    // for(int i=0;i<m;i++)
    //     for(int j=0;j<n;j++)
    //         cout<<arr[i][j]<<"   ";
    //         // cout<<endl;



    // int **arr;                                                                  //method 3
    // arr=new int  *[m];
    // for(int i=0;i<m;i++)
    //     arr[i]=new int [n];
    // for(int i=0;i<m;i++)
    //     for(int j=0;j<n;j++)
    //     {
    //         arr[i][j]=10;
    //         cout<<arr[i][j]<<"   ";
    //     }



    // int *arr[m];                                                                  //method 4
    // for(int i=0;i<m;i++)
    //     arr[i]=new int [n];
    // for(int i=0;i<m;i++)
    //     for(int j=0;j<n;j++)
    //     {
    //         arr[i][j]=10;
    //         cout<<arr[i][j]<<"   ";
    //     }



    // vector<int> arr[m];                                                             //method 5
    // for(int i=0;i<m;i++)
    //     for(int j=0;j<n;j++)
    //     {
    //         arr[i].push_back(10); 
    //         cout<<arr[i][j]<<"   ";
    //     }
    vector<vector<int>> arr;                                                             //method 6
    for(int i=0;i<m;i++)
    {
        vector<int> v;
        for(int j=0;j<n;j++)
        {
            v.push_back(10);
        }
        arr.push_back(v);
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<"   ";
    

    
}
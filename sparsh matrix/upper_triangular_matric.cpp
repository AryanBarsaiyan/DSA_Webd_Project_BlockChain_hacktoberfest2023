#include<bits/stdc++.h>
using namespace std;
int main()
{
    int matric[5][5]={
                                {1,2,3,4,5},
                                {0,1,2,3,4},
                                {0,0,1,2,3},
                                {0,0,0,1,2},
                                {0,0,0,0,1},
                            };
    int n=5;
    int size=(n*(n+1))/2;
    cout<<size<<endl;
    int rowmajor[size];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(j>=i)
            {
                int index=(n*(n+1))/2 - ((n-i)*(n-i+1))/2 +j-i;
                rowmajor[index]=matric[i][j];
            }
        }
    }

    for(int i=0;i<size;i++)
    {
        cout<<rowmajor[i]<<"  ";
    }

    int columnmajor[size];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(j>=i
            )
            {
                int index=(j*(j+1))/2 + i;
                columnmajor[index]=matric[i][j];
            }
        }
    }

    cout<<endl<<endl;

    for(int i=0;i<size;i++)
    {
        cout<<columnmajor[i]<<"  ";
    }
}
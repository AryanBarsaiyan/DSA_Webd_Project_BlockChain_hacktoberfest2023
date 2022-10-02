#include<bits/stdc++.h>
using namespace std;
int main()
{
    int matric[4][4]={
                                {1,0,0,0},
                                {1,2,0,0},
                                {1,2,3,0},
                                {1,2,3,4},
                            };
    int n=4;
    int size=(n*(n+1))/2;
    cout<<size<<endl;
    int rowmajor[size];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(i>=j)
            {
                int index=(i*(i+1))/2 +j;
                rowmajor[index]=matric[i][j];
            }
        }
    }

    for(int i=0;i<size;i++)
    {
        cout<<rowmajor[i]<<"  ";
    }

    int columnmajor[size];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(i>=j)
            {
                int index=((n*(n+1))/2 - ((n-j)*(n-j+1))/2 + i - j);
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
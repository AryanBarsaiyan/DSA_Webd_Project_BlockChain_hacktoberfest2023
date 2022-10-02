#include<bits/stdc++.h>
using namespace std;
int main()
{
    int diagonalmatric[4][4]={
                                {1,0,0,0},
                                {0,2,0,0},
                                {0,0,3,0},
                                {0,0,0,4},
                            };
    int newmatric[4];
    for(int i=0;i<4;i++)
        newmatric[i]=diagonalmatric[i][i];
    
    for(int i=0;i<4;i++)
        cout<<newmatric[i]<<" ";
}
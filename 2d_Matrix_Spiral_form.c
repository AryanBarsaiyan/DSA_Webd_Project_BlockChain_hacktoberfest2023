#include <iostream>
using namespace std;
int main()
{
           int row_end,col_end,a[200][200],row_start=0,col_start=0;
           cout<<"Enter the number of rows:";
           cin>>row_end;
           cout<<"Enter the number of columns:";
           cin>>col_end;
           cout<<"Enter the array\n";
           for(int i=0;i<row_end;i++)
           {
                      for(int j=0;j<col_end;j++)
                                 cin>>a[i][j];
           }
           cout<<"Spiral form\n";
           while(row_start<row_end&&col_start<col_end)
           {
                      for(int j=col_start;j<col_end;j++)
                                 cout<<a[row_start][j]<<"  ";
                      row_start++;
                      for(int j=row_start;j<row_end;j++)
                                 cout<<a[j][col_end-1]<<"  ";
                      col_end--;
                      if(row_start<row_end)
                      {
                                 for(int j=col_end-1;j>=col_start;j--)
                                            cout<<a[row_end-1][j]<<"  ";
                                 row_end--;
                      }
                      if(col_start<col_end)
                      {
                                 for(int j=row_end-1;j>=row_start;j--)
                                            cout<<a[j][col_start]<<"  ";
                                 col_start++;
                      }
           }
}

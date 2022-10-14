#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cout << "*" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "*";
        int a = 1;
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            if (j <= i)
            {
                cout << j;
            }
            else
            {
                cout << i - a;
                a++;
            }
        }

        cout << "*" << endl;
    }
    for (int i = n - 1; i > 0; i--)
    {
        cout << "*";
        int a = 1;
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            if (i >= j)
            {
                cout << j;
            }
            else
            {
                cout << i - a;
                a++;
            }
        }

        cout << "*" << endl;
    }
    cout << "*";
    return 0;
}
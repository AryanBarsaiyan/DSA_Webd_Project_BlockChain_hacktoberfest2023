#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vpi vector<pi>
#define vpll vector<pll>
#define sz(x) ((int)(x).size())
#define prec(n) fixed << setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
void IOS()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
#endif
}
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
int longestCommonSubsequence(string x, string y)
{
    int n = x.size(), m = y.size();
    string s;
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[n][m];
}

void shortestCommonSubsequence(string x, string y)
{
    int n = x.size(), m = y.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    string s;
    int i = x.size(), j = y.size();
    while (i > 0 and j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            s.pb(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                s.pb(y[j - 1]);
                j--;
            } // else find the max of up and right position of dp table and move accordingly to up or left

            else
            {
                s.pb(x[i - 1]);

                i--;
            }
        }
    }
    while(i>0)
    {s.pb(x[i-1]);i--;}
    while(j>0)
    {s.pb(y[j-1]);j--;}
    reverse(s.begin(), s.end());
    cout << s << endl;
}
int main()
{
    IOS();
    FAST;

    string x, y;
    cin >> x >> y;
    shortestCommonSubsequence(x, y);
    cout << "Length is:";
    cout << x.size() + y.size() - longestCommonSubsequence(x, y) << endl; //s.size()
    return 0;
}
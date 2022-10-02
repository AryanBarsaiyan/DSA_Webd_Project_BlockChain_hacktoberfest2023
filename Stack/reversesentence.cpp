#include <bits/stdc++.h>
#include <stack>
using namespace std;
void reversesentence(string s)
{
    stack<string> st;
    for(int i=0;i<s.length();i++)
    {
        string words="";
        while(s[i]!=' '&&i<s.length())
        {
            words+=s[i];
            i++;
        }
        st.push(words);
    }
while(!st.empty())
{
    cout<<st.top()<<" ";
    st.pop();
}cout<<endl;
}
int main()
{  string s="Hey, how are you doing?";
reversesentence(s);
    return 0;
}
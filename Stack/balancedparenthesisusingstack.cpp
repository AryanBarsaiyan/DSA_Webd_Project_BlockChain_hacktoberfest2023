#include <iostream>
#include <stack>
using namespace std;
bool isbanced(char *a)
{
    stack<char> s;
    for (int i = 0; a[i] != '\0'; ++i)
    {
        char ch = a[i];
        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            s.push(ch);
            break;
        case ')':
            if (!s.empty() and s.top() == '(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            break;
        case '}':
            if (!s.empty() and s.top() == '{')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            break;
        case ']':
            if (!s.empty() and s.top() == '[')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            //break;
        }
    }
    return s.size() == 0;
}
int main()
{
    char a[] = "{a+(b*c(a+a))[a*d]}";

    if (isbanced(a))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}
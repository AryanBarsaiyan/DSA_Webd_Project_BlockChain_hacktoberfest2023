#include <iostream>
#include <vector>
using namespace std;
#define pb push_back
class stack
{
    vector<int> v;

public:
    void push(int d)
    {
        v.pb(d);
    }
    void pop()
    {
        v.pop_back();
    }

    bool empty()
    {
        return v.size() == 0;
    }

    int top()
    {
        return v[v.size() - 1];
    }
};
int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while (s.empty() != true)
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
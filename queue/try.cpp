#include<bits/stdc++.h>
using namespace std;
class Stack
{
    public:
        queue<int> q1,q2;
        void Push(int x)
        {
            while(q1.empty()==false)
            {
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(x);
            while(q2.empty()==false){
                q1.push(q2.front());
                q2.pop();
            }
        }
        void Pop()
        {
            q1.pop();
        }
        int top()
        {
            q1.front();
        }
};
int main()
{

}
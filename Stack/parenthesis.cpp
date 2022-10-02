//Parenthesis matching
/*  //BEST APPROACH
#include <bits/stdc++.h>
using namespace std;
unordered_map<char,int> symbols={{'[',-1},{'{',-2},{'(',-3},{']',+1},{'}',+2},{')',+3}};
string isbalanced(string s)
{
    stack<char> st;
    for(char brackets:s)
    {
        if(symbols[brackets]<0)
        st.push(brackets);
        else
        {
            if(st.empty()) 
            return "NO";
            char top=st.top();
            st.pop();
            if(symbols[top]+symbols[brackets]!=0)
            return "NO";
        }
    }
    if(st.empty())
    return "Yes";
    return "No";
    
}
int main()
{ string s;
 cin>>s;
    cout<<isbalanced(s);
    return 0;
}

*/
/*	Given an expression string exp, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in exp. Also calculate time and space complexity of your program.
Input: exp = “[()]{}{[()()]()}” 
Output: Balanced
Input: exp = “[(])” 
Output: Not Balanced 
*/
#include <bits/stdc++.h>
using namespace std;
struct Node{
    char data;
    Node *next;
}*top=NULL;
void push(char x)
{
    struct Node *t;
    t=new Node;
    if(t==NULL)
    cout<<"Stack is full";
    else 
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}
char pop()
{struct Node *t;
t=top;
char x=-1;
if(top==NULL)
cout<<"Stack is Empty";
else
{
    t=top;
    top=top->next;
    x=t->data;
    delete t;
}
return x;
}
int isbalanced(string x)
{
    for(int i=0;x[i]!='\0';i++)
{
    if(x[i]=='(')
    push(x[i]);
    else if(x[i]==')')
    {
        if(top==NULL)
        return 0;
        pop();
    }
}
if(top==NULL)
return 1;
else 
return 0;
   
}
int main()
{ string x="[()]{}{[()()]()}";
int z=isbalanced(x);
if(z)
cout<<x<<"-IS BALANCED"<<endl;
else
cout<<x<<"-NOT BALANCED"<<endl;
    return 0;
}
/*
#include <stack>
#include <string>
#include <iostream>

using namespace std;

string isBalanced(string s) {
    stack<char> st;  
    
    for (auto c: s) {
        switch (c) {
            case '{':
            case '(':
            case '[':
                st.push(c);
                break;
            case '}':
                if (st.empty() || (st.top() != '{')) {
                    return "NO";
                }
                st.pop();
                break;
            case ')':
                if (st.empty() || (st.top() != '(')) {
                    return "NO";
                }
                st.pop();
                break;
            case ']':
                if (st.empty() || (st.top() != '[')) {
                    return "NO";
                }
                st.pop();
                break;
        }
    }
    
    return st.empty() ? "YES" : "NO";
}


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        cout << isBalanced(s) << endl;
    }
    return 0;
}
*/
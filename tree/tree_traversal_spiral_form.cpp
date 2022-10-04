#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        int key;
        node *left;
        node *right;
        node(int x)
        {
            key=x;
            left=right=NULL;
        }
};

void printspiral(node * root)                                                                               //method 1
{
    if(root==NULL)   return;
    queue<node *>q;
    q.push(root);
    int level=0;
    while(q.empty()==false)
    {
        int count=q.size();
        level++;
        stack<int>s;
        for(int i=0;i<count;i++)
        {
            node *cur=q.front();
            q.pop();
            if(level%2==0)
            {
                s.push(cur->key);
            }
            else    
                cout<<cur->key<<" ";
            if(cur->left!=NULL)
                q.push(cur->left);
            if(cur->right!=NULL)
                q.push(cur->right);
        }
        while(s.empty()==false)
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }
}

void printSpiralEff(node * root)
{
    if(root==NULL)  return ;
    stack<node *> s1,s2;
    s1.push(root);
    bool flag=false;
    while(s1.empty()==false || s2.empty()==false)
    {
        flag= !flag;
        int count;
        if(flag) count=s1.size();
        else    count=s2.size();
        for(int i=0;i<count;i++)
        {
            if(flag)
            {
                node * cur=s1.top();
                s1.pop();
                cout<<cur->key<<" ";
                if(cur->left!=NULL) s2.push(cur->left);
                if(cur->right!=NULL) s2.push(cur->right);
            }
            else
            {
                node *cur=s2.top();
                s2.pop();
                cout<<cur->key<<" ";
                if(cur->right!=NULL) s1.push(cur->right);
                if(cur->left!=NULL) s1.push(cur->left);
            }
        }
    }
}

int main()
{
    // node *root=new node(10);                                                         //test case 1;
    // root->left=new node(20);
    // root->left->left=new node(40);
    // root->left->right=new node(50);
    // root->right=new node(30);

    // node *root=new node(30);                                                         //test case 2;
    // root->right=new node(50);
    // root->right->left=new node(60);
    // root->right->left->right=new node(10);

    node *root=new node(10);                                                                                     //test case 3   
    root->left=new node(30);
    root->left->left=new node(80);
    root->left->left->right=new node(70);
    root->right=new node(40);
    root->right->left=new node(60);
    root->right->right=new node(20);

    printspiral(root);
    cout<<endl;
    printSpiralEff(root);
}
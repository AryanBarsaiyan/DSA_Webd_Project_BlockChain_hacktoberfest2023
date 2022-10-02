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
void inorder(node * root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<"  ";
        inorder(root->right);
    }
}
void iterativeinorder(node *root)
{
    stack<node *>s;
    node *cur=root;
    while(cur!=NULL || s.empty()==false)
    {
        while(cur!=NULL)
        {
            s.push(cur);
            cur=cur->left;
        }
        cur=s.top(); s.pop();
        cout<<cur->key<<"  ";
        cur=cur->right;
    }2
}
int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right=new node(30);
    inorder(root);
    cout<<endl;
    iterativeinorder(root);
}
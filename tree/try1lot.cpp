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
void level_order_traversal(node *root)
{
    if(root==NULL)
        return;
    queue<node *> q;
    q.push(root);
    while(q.empty()!=true)
    {
        node*cur=q.front();
        cout<<cur->key<<"  ";
        q.pop();
        if(cur->left!=NULL)
            q.push(cur->left);
        if(cur->right!=NULL)
            q.push(cur->right);
    }
}
int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right=new node(30);
    level_order_traversal(root);
}
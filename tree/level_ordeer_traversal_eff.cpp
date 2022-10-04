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
void print(node *root)
{
    if(root==NULL) return;
    queue<node *>q;
    q.push(root);
    while(q.empty()!=true)
    {
        node *cur=q.front();
        q.pop();
        cout<<cur->key<<" ";
        if(cur->left!=NULL)
            q.push(cur->left);
        if(cur->right!=NULL)
            q.push(cur->right);
    }
}
int main()
{
    // node *root=new node(10);
    // root->left=new node(20);
    // root->left->left=new node(40);
    // root->left->right=new node(50);
    // root->right=new node(30);

     node *root=new node(10);                                                                                     //test case 3   
    root->left=new node(30);
    root->left->left=new node(80);
    root->left->left->right=new node(70);
    root->right=new node(40);
    root->right->left=new node(60);
    root->right->right=new node(20);
    print(root);
}
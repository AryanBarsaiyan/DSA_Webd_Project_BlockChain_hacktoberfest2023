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
        cout<<root->key<<"  ";
        inorder(root->left);
        inorder(root->right);
    }
}
void iterativepreorder(node *root)
{
    stack<node *>s;
    s.push(root);
    while(s.empty()==false)
    {
        node *cur=s.top();
        cout<<cur->key<<"  ";
        s.pop();
        if(cur->right!=NULL) s.push(cur->right);
        if(cur->left!=NULL) s.push(cur->left);
    }

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
    iterativepreorder(root);
}
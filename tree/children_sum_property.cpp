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
bool IsChildrenSum(node *root)
{
    if(root==NULL)  return true;
    if(root->left == NULL && root->right ==NULL)     return true;
    int sum=0;
    if(root->left!=NULL)    sum+=root->left->key;
    if(root->right!=NULL)   sum+=root->right->key;

    return (root->key==sum && IsChildrenSum(root->left) && IsChildrenSum(root->right));
}
int main()
{
    // node *root=new node(10);                                                  //test case 1
    // root->left=new node(20);
    // root->left->left=new node(40);
    // root->left->right=new node(50);
    // root->right=new node(30);

    node *root = new node(10);
    root->left = new node(8);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(5);
    root->right->right = new node(2);
    print(root);
    cout<<endl<<IsChildrenSum(root);
}
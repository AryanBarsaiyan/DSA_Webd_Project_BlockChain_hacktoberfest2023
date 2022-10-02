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
int height(node * root)
{
    if(root==NULL)
        return 0;
    else
        return (max(height(root->left),height(root->right))+1);
}
void print(node * root,int i,int k)
{
    if(root!=NULL)
    {
        print(root->left,i+1,k);
        if(i==k)
             cout<<root->key<<"  ";
        print(root->right,i+1,k); 
    }
}
int main()
{
    node * root =new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    int x=height(root);
    for(int i=0;i<x;i++)
    {
        print(root,0,i);
    }
}
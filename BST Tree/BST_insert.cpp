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
void printpost(node * root)
{
    if(root!=NULL)
    {
        printpost(root->left);
        printpost(root->right);
        cout<<root->key<<" ";
    }
}
void printin(node *root)
{
    if(root!=NULL)
    {
        printin(root->left);
        cout<<root->key<<" ";
        printin(root->right);
    }
}

node * Ctree(int in[],int po[],int is,int ie)
{
    if(is>ie)   return NULL;
    static int index=ie;
    node *root=new node(po[index--]);
    int preindex=0;
    for(int i=is;i<=ie;i++)
    {
        if(root->key==in[i])
        {
            preindex=i;
            break;
        }
    }
    root->right=Ctree(in,po,preindex+1,ie);
    root->left=Ctree(in,po,is,preindex-1);
    return root;
}
node * InsertRoot(node * root,int x)
{
    if(root==NULL)
    {
        root=new node(x);
        return root;
    }
    node * cur=root;
    node * parent=root;
    while(cur!=NULL)
    {
        parent=cur;
        if(cur->key==x)
            return root;
        else if(cur->key>x)
            cur=cur->left;
        else
            cur=cur->right;
    }
    cur=new node(x);
    if(parent->key<x)
    parent->right=cur;
    else
    parent->left=cur;
    return root;
}

node *insertRootRecursive(node *root,int x)
{
    if(root==NULL)
        root=new node(x);
    else if(root->key<x)
        root->right=insertRootRecursive(root->right,x);
    else
        root->left=insertRootRecursive(root->left,x);
    return root;

}

int main()
{
    int in[]={5,10,12,15,18};
    int post[]={5,12,18,15,10};
    node * root=Ctree(in,post,0,4);
    //cout<<endl;
   // printpost(root);
   //root=insertRootRecursive(root,20);
   root=InsertRoot(root,20);
   printin(root);
   cout<<endl;
   printpost(root);
    
}
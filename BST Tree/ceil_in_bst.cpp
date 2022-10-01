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

node *getsuccessor(node * root)
{
    root=root->right;
    while(root!=NULL && root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

node *ceil_(node * root,int x)
{
    node * res=NULL;
    while(root!=NULL)
    {
        if(root->key==x)
            return root;
        else if(root->key<x)
            root=root->right;
        else
        {
            res=root;
            root=root->left;
        }
    }
    return res;
}

int main()
{
    int in[]={5,10,12,15,30};
    int post[]={5,12,30,15,10};
    node * root=Ctree(in,post,0,4);
    //cout<<endl;
   // printpost(root);
//    printin(root);
//    cout<<endl;
//    printpost(root);
    cout<<ceil_(root,40)->key;
  
}
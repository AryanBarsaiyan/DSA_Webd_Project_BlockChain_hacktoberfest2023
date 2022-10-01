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

node * delete_key(node * root,int x)
{
    if(root==NULL) return root;
    else if(root->key>x)
        root->left=delete_key(root->left,x);
    else if(root->key<x)
        root->right=delete_key(root->right,x);
    else
    {
        if(root->right==NULL)
        {
            node * cur=root->left;
            delete root;
            return cur;
        }
        else if(root->left==NULL)
        {
            node * cur=root->right;
            delete root;
            return cur;
        }
        else{
            node * successor=getsuccessor(root);
            root->key=successor->key;
            root->right=delete_key(root->right,successor->key);
        }
    }
        return root;
}

int main()
{
    int in[]={10,30,40,50,60,70,80};
    int post[]={10,40,30,60,80,70,50};
    node * root=Ctree(in,post,0,6);
    //cout<<endl;
   // printpost(root);
   root=delete_key(root,50);
   printin(root);
   cout<<endl;
   printpost(root);
  
}
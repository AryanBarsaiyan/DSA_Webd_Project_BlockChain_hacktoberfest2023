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
void Search(node *root,int key)
{
    if(root==NULL)  cout<<"not found";
    while(root!=NULL && root->key !=key)
    {
        if(key<root->key)
            root=root->left;
        else
            root=root->right;
    }
    if(root==NULL)
        cout<<"not found";
    else
        cout<<"key found";
}
bool SearchRecursive(node *root,int key)
{
    if(root==NULL)
        return false;
    else if(root->key==key)
        return true;
    else if(root->key>key)
        return SearchRecursive(root->left,key);
    else
        return SearchRecursive(root->right,key);
}

int main()
{
    int in[]={3,5,15,16,18,20,80};
    int post[]={3,5,16,18,80,20,15};
    node * root=Ctree(in,post,0,6);
    //cout<<endl;
   // printpost(root);
    Search(root,21);
    cout<<endl<<SearchRecursive(root,21);
}
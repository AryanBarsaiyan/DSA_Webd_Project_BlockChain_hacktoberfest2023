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
void Print_lOT_lineBYLine(node * root)
{
    if(root==NULL) return;
    queue<node *>q;
    q.push(root);
    while(q.empty()==false)
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            node *cur=q.front();
            q.pop();
            cout<<cur->key<<" ";
            if(cur->left!=NULL)
                q.push(cur->left);
            if(cur->right!=NULL)
                q.push(cur->right);
        }
        cout<<endl;
    }
}
bool findpath(node * root,vector<node *> &v,int n)                                              //naive
{
    if(root==NULL)  return false;
    v.push_back(root);
    if(root->key==n)    return true;
    if(findpath(root->left,v,n) || findpath(root->right,v,n))
    {
        return true;
    }
    v.pop_back();
    return false;
}
node * getLCA(node *root,int n1,int n2)                                                         //naive
{
    vector<node *> v1,v2;
    if(!findpath(root,v1,n1) || !findpath(root,v2,n2))   return NULL;
    int count=min(v1.size(),v2.size());
    for(int i=1;i<count;i++)
    {
        if(v1[i]!=v2[i])
            return v1[i-1];
    }
    return NULL;
}

node *getLCAeff(node *root,int n1,int n2)
{
    if(root==NULL)  return NULL;
    if(root->key==n1 || root->key==n2)
    {
        return root;
    }
    node * lca1=getLCAeff(root->left,n1,n2);
    node * lca2=getLCAeff(root->right,n1,n2);
    if(lca1!=NULL && lca2!=NULL)
        return root;
    if(lca1!=NULL)
        return lca1;
    else 
        return lca2;
}
int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right=new node(30);
    Print_lOT_lineBYLine(root);
    cout<<getLCA(root,40,50)->key;
    cout<<endl<<getLCAeff(root,40,50)->key;
}
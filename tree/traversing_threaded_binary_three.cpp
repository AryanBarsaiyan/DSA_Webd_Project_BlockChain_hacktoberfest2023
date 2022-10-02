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
        inorder(root->left);
        cout<<root->key<<"  ";
        inorder(root->right);
    }
}
void preorder(node * root)
{
    if(root!=NULL)
    {
        cout<<root->key<<"  ";
        preorder(root->left);
        preorder(root->right);
    }
}
void threadediorder(node *root)
{
    node *cur=root;
    while(cur!=NULL)
    {
        if(cur->left==NULL)
        {
            cout<<cur->key<<" ";
            cur=cur->right;
        }
        else{
            node *prev=cur->left;
            while(prev->right && prev->right!=cur)
                prev=prev->right;
                if(prev->right==NULL)
                {
                    prev->right=cur;
                   // cout<<cur->key<<" ";
                    cur=cur->left;
                }
                else{
                    cout<<cur->key<<"  ";
                    prev->right=NULL;
                    cur=cur->right;
                }
        }
    }
}
void threadedpreorder(node *root)
{
    node *cur=root;
    while(cur!=NULL)
    {
        if(cur->left==NULL)
        {
            cout<<cur->key<<" ";
            cur=cur->right;
        }
        else{
            node *prev=cur->left;
            while(prev->right && prev->right!=cur)
                prev=prev->right;
                if(prev->right==NULL)
                {
                    prev->right=cur;
                    cout<<cur->key<<"  ";
                    cur=cur->left;
                }
                else{
                    prev->right=NULL;
                    cur=cur->right;
                }
        }
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
    threadediorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    threadedpreorder(root);
}
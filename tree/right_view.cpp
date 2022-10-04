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

void print_right_view(node *root)                                                                                            //iterative
{
    if(root==NULL)
        return;
    queue<node *>q;
    q.push(root);
   // cout<<root->key<<" ";
    while(q.empty()==false)
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            node *cur=q.front();
            q.pop();
            if(i==count-1)
            {
                cout<<cur->key<<" ";
            }
            if(cur->left!=NULL)
                q.push(cur->left);
            if(cur->right!=NULL)
                q.push(cur->right);
        }
    }
}
void printright(node * root,int level)                                               //recursive starting
{
    static int max_level=0;
    if(root==NULL)
        return;
    if(max_level<level)
    {
        cout<<root->key<<" ";
        max_level=level;
    }
    printright(root->right,level+1);
    printright(root->left,level+1);
}

void right_view_recursive(node * root)                                                     //recursive
{
    printright(root,1);
}
int main()
{
    // node *root=new node(10);                                                         //test case 1;
    // root->left=new node(20);
    // root->left->left=new node(40);
    // root->left->right=new node(50);
    // root->right=new node(30);

    // node *root=new node(30);                                                         //test case 2;
    // root->right=new node(50);
    // root->right->left=new node(60);
    // root->right->left->right=new node(10);

    node *root=new node(10);                                                                                     //test case 3   
    root->left=new node(30);
    root->left->left=new node(80);
    root->left->left->right=new node(70);
    root->right=new node(40);
    root->right->left=new node(60);
    root->right->right=new node(20);
    Print_lOT_lineBYLine(root);
    print_right_view(root);
    cout<<endl;
    right_view_recursive(root);
}
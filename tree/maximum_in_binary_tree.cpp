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
int max_num_itrative(node * root)                                                                //itrative
{
    int MAX=INT_MIN;
    if(root==NULL)  return MAX;
    queue<node *>q;
    q.push(root);
    while(q.empty()!=true)
    {
        node *cur=q.front();
        q.pop();
        MAX=max(cur->key,MAX);
        if(cur->left!=NULL)
            q.push(cur->left);
        if(cur->right!=NULL)
            q.push(cur->right);
    }
    return MAX;
}
int max_num(node *root)                                                                         //recursive
{
    if(root==NULL)
        return INT_MIN;
    return max(root->key,max(max_num(root->left),max_num(root->right)));
}
int main()
{
    node *root=new node(10);                                                                                 //test case 1
    root->left=new node(20);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right=new node(30);

    // node *root=NULL;                                                                                           //test case 2

    // node *root=new node(10);                                                                                     //test case 3   
    // root->left=new node(30);
    // root->left->left=new node(80);
    // root->left->left->right=new node(70);
    // root->right=new node(40);
    // root->right->left=new node(60);
    // root->right->right=new node(20);
    Print_lOT_lineBYLine(root);
    cout<<max_num_itrative(root)<<endl;
    cout<<max_num(root);
}
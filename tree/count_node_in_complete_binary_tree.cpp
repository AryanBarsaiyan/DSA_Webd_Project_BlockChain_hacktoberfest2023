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
int countnode_genereal(node * root)                                                                     //aplicable for ANY tree
{
    if(root==NULL)  return 0;

    return 1+countnode_genereal(root->left)+countnode_genereal(root->right);
}
int countnode_eff(node *root)
{
    if(root==NULL)  return 0;
    int lh=0,rh=0;
    node *cur=root;

    while(cur!=NULL)
    {
        lh++;
        cur=cur->left;
    }
    cur=root;
    while(cur!=NULL)
    {
        rh++;
        cur=cur->right;
    }
    if(lh==rh)
    {
        return pow(2,lh)-1;
    }
    return 1+countnode_eff(root->left)+countnode_eff(root->right);
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
    cout<<endl<<countnode_genereal(root);
    cout<<endl<<countnode_eff(root);   
}
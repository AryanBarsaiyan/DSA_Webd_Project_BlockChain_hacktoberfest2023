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
int height_naive(node * root)                                                                                         //naive soln
{
    if(root==NULL)  return 0;
    return max(height_naive(root->left),height_naive(root->right))+1;
}
int diameter_naive(node *root)
{
    if(root==NULL)  return 0;
    int d1=1+height_naive(root->left)+height_naive(root->right);
    int d2=diameter_naive(root->left);
    int d3=diameter_naive(root->right);
    return max(d1,max(d2,d3));
}
int height_eff(node *root,int &ans)                                                                                     //eff soln
{
    if(root==NULL)  return 0;
    int lh=height_eff(root->left,ans);
    int rh=height_eff(root->right,ans);
    ans=max(ans,lh+rh+1);
    return max(lh,rh)+1;
}
int diameter_eff(node *root)
{
    if(root==NULL)
        return 0;
    int ans=INT_MIN;
    height_eff(root,ans);
    return ans;
}
int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right=new node(30);
    Print_lOT_lineBYLine(root);
    cout<<diameter_naive(root);
    cout<<endl<<diameter_eff(root);
}
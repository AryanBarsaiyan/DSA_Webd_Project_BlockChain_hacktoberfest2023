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

void vertical_traversal(node *root)
{
    queue<pair<node *,int>> q;
    map<int,vector<int>> mp;
    q.push({root,0});
    while (q.empty()==false)
    {
        auto it=q.front();
        q.pop();
        node *cur=it.first;
        int level=it.second;
        mp[level].push_back(cur->key);
        if(cur->left!=NULL)
            q.push({cur->left,level-1});
        if(cur->right!=NULL)
            q.push({cur->right,level+1});
    }
    for(auto x:mp)
    {
        vector<int> v=x.second;
        for(auto y:v)
            cout<<y<<" ";
        cout<<endl;
    }
    
}
int main()
{
    int in[]={40,20,50,10,30};
    int post[]={40,50,20,30,10};
    node * root=Ctree(in,post,0,4);
    vertical_traversal(root);
    cout<<endl;    
}
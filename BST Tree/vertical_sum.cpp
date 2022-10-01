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

void v_sum_level_order_traversal(node *root)                                                                                            //iterative
{
    if(root==NULL)
        return;
    queue<pair<node *,int>> q;
    map<int,int> mapp;
    q.push({root,0});
    while(q.empty()==false)
    {
        auto it=q.front();
        q.pop();
        node *cur=it.first;
        int line=it.second;
        
        mapp[line]+=cur->key;

        if(cur->left!=NULL)
            q.push({cur->left,line-1});
        if(cur->right!=NULL)
            q.push({cur->right,line+1});
    }
    for(auto it:mapp)
    {
        cout<<it.second<<"  ";
    }
}
void vSum_formation(node * root,int level,map<int,int> &m)
{
    if(root !=NULL)
    {
        vSum_formation(root->left,level-1,m);
        m[level]+=root->key;
        vSum_formation(root->right,level+1,m);
    }
}

void vSum(node * root)
{
    map<int,int> m;
    vSum_formation(root,0,m);
    for(auto it:m)
    {
        cout<<it.second<<"  ";
    }
}
int main()
{
    int in[]={5,20,15,10,30};
    int post[]={5,15,20,30,10};
    node * root=Ctree(in,post,0,4);
    v_sum_level_order_traversal(root);
    cout<<endl;    
    vSum(root);
}
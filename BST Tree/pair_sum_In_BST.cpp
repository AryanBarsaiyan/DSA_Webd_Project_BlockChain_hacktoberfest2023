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

void get_vector(node * root,vector<int> &v)
{
    if (root!=NULL)
    {
        get_vector(root->left,v);
        v.push_back(root->key);
        get_vector(root->right,v);
    }
}

bool pair_sum(vector<int> v,int val)
{
    int ie=v.size()-1;
    int is=0;
    if(ie==0)    return false;
    while(is<ie)
    {
        if((v[is]+v[ie]) ==val)
            return true;
        else if((v[is]+v[ie]) >val)
            ie--;
        else
            is++;
    }
    return false;
}

bool pair_sum_eff(node * root,int key,unordered_set<int> &s)
{                                                                               //using hashing 
    if(root==NULL)  return false;

    if(pair_sum_eff(root->left,key,s)==true)
        return true;
    if(s.find(key-root->key)!=s.end())
        return true;
    else
        s.insert(root->key);
    return pair_sum_eff(root->right,key,s);
}
int main()
{
    int in[]={5,10,12,15,30};
    int post[]={5,12,30,15,10};
    node * root=Ctree(in,post,0,4);
    vector<int> v;
    get_vector(root,v);
    unordered_set<int>s;
    cout<<pair_sum_eff(root,27,s)<<endl;
    cout<<pair_sum(v,27);

  
}
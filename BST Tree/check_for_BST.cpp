#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        int key;
        node *left,*right;
        node(int x)
        {
            key=x;
            left=right=NULL;
        }
};
node *cstree(int io[],int pr[],int is,int ie)
{
    if(is>ie)   return NULL;
    static int index=0;
    node * root=new node(pr[index]++);
    int preindex=0;
    for(int i=is;i<ie;i++)
    {
        if(root->key==io[i])
        {
            preindex=i;
            break;
        }
    }
    root->left = cstree(io,pr,is,index-1);
    root->right = cstree(io,pr,index+1,ie);
}
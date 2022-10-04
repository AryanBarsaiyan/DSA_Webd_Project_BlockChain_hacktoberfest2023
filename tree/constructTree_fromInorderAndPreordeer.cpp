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
void printpre(node * root)
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        printpre(root->left);
        printpre(root->right);
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

void printpost(node *root)
{
    if(root!=NULL)
    {
        printpost(root->left);
        printpost(root->right);
        cout<<root->key<<" ";
    }
}
node *constructTree(int in[],int pr[],int is,int ie)
{
    if(is>ie)   return NULL;
    static int index=0;
    node *root=new  node(pr[index++]);
    int inindex=0;
    for(int i=is;i<=ie;i++)
    {
        if(root->key==in[i])
        {
            inindex=i;
            break;
        }
    }
    root->left=constructTree(in,pr,is,inindex-1);
    root->right=constructTree(in,pr,inindex+1,ie);
    return root;
}

int main()
{
    int in[]={20,10,40,30,50};
    int pre[]={10,20,30,40,50};
    node *root=constructTree(in,pre,0,4);
    printin(root);
    cout<<endl;
    printpre(root);
    cout<<endl;
    printpost(root);    
   
}
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

void printKth(node * root,int k)
{
    static int count=0;
    if(root!=NULL)
    {
        printKth(root->left,k);
        count++;
        if(count==k)
        {
            cout<<root->key<<endl;
            return ;
        }
        printKth(root->right,k);
    }
}

int main()
{
    int in[]={5,10,12,15,30};
    int post[]={5,12,30,15,10};
    node * root=Ctree(in,post,0,4);
    //cout<<endl;
   // printpost(root);
//    printin(root);
//    cout<<endl;
//    printpost(root);
    printKth(root,3);
  
}
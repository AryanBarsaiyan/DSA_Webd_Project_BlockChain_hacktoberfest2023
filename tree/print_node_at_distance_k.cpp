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
            left=NULL;
            right=NULL;
        }
};
void print(node * root,int i,int k)
{
    if(root!=NULL)
    {
        print(root->left,i+1,k);
        if(i==k)
             cout<<root->key<<"  ";
        print(root->right,i+1,k); 
    }
}
int main()
{
    // node *root=new node(10);                                                                     //test case:1
    // root->left=new node(20);
    // root->left->left=new node(40);
    // root->left->right=new node(50);
    // root->right=new node(30);
    // root->right->right=new node(70);
    // int k=2;

    // node *root=new node(10);                                                                         //test case: 2
    // root->left=new node(20);
    // root->left->left=new node(30);
    // int k=1;

    node *root=new node(10);                                                                            //test case:3
    root->left=new node(6); 
    root->right=new node(8);
    root->right->right=new node(7);
    root->right->right->left=new node(11);
    root->right->right->right=new node(12);
    int k=3;
    print(root,0,k);
}
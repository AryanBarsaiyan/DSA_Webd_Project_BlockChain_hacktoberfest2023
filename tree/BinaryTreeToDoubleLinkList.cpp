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
void printTreeInorder(node * root)
{
    if(root!=NULL)
    {
        printTreeInorder(root->left);
        cout<<root->key<<"  ";
        printTreeInorder(root->right);
    }
}

node *BTTDLL(node * root)
{
    if(root==NULL)  return root;
    static node *prev=NULL;
    node *head=BTTDLL(root->left);
    if(prev==NULL)  head=root;
    else
    {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    BTTDLL(root->right);
    return head; 
}
void printdll(node *root)
{
    while(root!=NULL)
    {
        cout<<root->key<<"  ";
        root=root->right;
    }
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

    // node *root=new node(10);                                                                                     //test case 3   
    // root->left=new node(30);
    // root->left->left=new node(80);
    // root->left->left->right=new node(70);
    // root->right=new node(40);
    // root->right->left=new node(60);
    // root->right->right=new node(20);

    node *root = new node(1);                                                       //test case 4
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    root->left->right->right = new node(5);
    root->left->right->right->right = new node(6);

    // node *root = new node(20);                                                      //test case 5
    // root->left = new node(8);
    // root->right = new node(22);
    // root->left->left = new node(5);
    // root->left->right = new node(3);
    // root->right->left = new node(4);
    // root->right->right = new node(25);
    // root->left->right->left = new node(10);
    // root->left->right->right = new node(14);
    printTreeInorder(root);
    cout<<endl;
    root=BTTDLL(root);
    printdll(root);

}
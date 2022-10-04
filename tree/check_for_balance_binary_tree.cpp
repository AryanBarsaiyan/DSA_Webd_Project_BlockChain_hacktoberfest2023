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
void print(node *root)
{
    if(root==NULL) return;
    queue<node *>q;
    q.push(root);
    while(q.empty()!=true)
    {
        node *cur=q.front();
        q.pop();
        cout<<cur->key<<" ";
        if(cur->left!=NULL)
            q.push(cur->left);
        if(cur->right!=NULL)
            q.push(cur->right);
    }
}
int height(node *root)                                                           //naive
{
    if(root==NULL)  return 0;
    return max(height(root->left),height(root->right))+1;
}
bool  isbalanced(node *root)                                                     //naive
{
    if(root==NULL) return true;
    int lh=height(root->left);
    int rh=height(root->right);

    return (abs(lh-rh)<=1 && isbalanced(root->left) && isbalanced(root->right));
}

int balance(node *root)                                                            //efficent
{
    if(root==NULL)  return 0;
    int lh=balance(root->left);
    if(lh==-1)  return -1;
    int rh=balance(root->right);
    if(rh==-1)  return -1;

    if(abs(rh-lh)>1)    return -1;
    else return max(lh,rh)+1;
}
bool isbalanced_eff(node * root)                                                //efficent
{
    if(balance(root)<0)
        return false;
    return true;
}


int main()
{
    // node *root=new node(10);                                                  //test case 1
    // root->left=new node(20);
    // root->left->left=new node(40);
    // root->left->right=new node(50);
    // root->right=new node(30);
    

    // node *root = new node(10);                                                //test case 2
    // root->left = new node(8);
    // root->right = new node(2);
    // root->left->left = new node(3);
    // root->left->right = new node(5);
    // root->right->right = new node(2);

    node* root = new node(1);                                                     // test case 3
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(8);
    print(root);
    cout<<endl<<isbalanced(root);
    cout<<endl<<isbalanced_eff(root);
}
#include<bits/stdc++.h>
using namespace std;
const int EMPTY=-1;
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
void preorder(node *root)
{
    if(root!=NULL)
    {
        cout<<root->key<<"  ";
        preorder(root->left);
        preorder(root->right);
    }
}

void serialize(node *root,vector<int> &v)
{
    if(root==NULL)
    {
        v.push_back(EMPTY);
        return;
    }
    v.push_back(root->key);
    serialize(root->left,v);
    serialize(root->right,v);
}

node *deserialize(vector<int>v)
{
    static int index=0;
    if(index==v.size()) return NULL;
    int val=v[index];
    index++;
    if(val==EMPTY)  return NULL;
    node *root=new node(val);
    root->left=deserialize(v);
    root->right=deserialize(v);
    return root;
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

    node *root=new node(10);                                                                                     //test case 3   
    root->left=new node(30);
    root->left->left=new node(80);
    root->left->left->right=new node(70);
    root->right=new node(40);
    root->right->left=new node(60);
    root->right->right=new node(20);

    vector<int>v;
    Print_lOT_lineBYLine(root);
    preorder(root);
    cout<<endl;
    serialize(root,v);
    for(auto it:v)
        cout<<it<<" ";  
    node * newroot=deserialize(v);
    cout<<endl;
    preorder(newroot);


}
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

void print_bottom_view(node *root)                                                                                            //iterative
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
        
        mapp[line]=cur->key;

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

    // node *root = new node(1);                                                       //test case 4
    // root->left = new node(2);
    // root->right = new node(3);
    // root->left->right = new node(4);
    // root->left->right->right = new node(5);
    // root->left->right->right->right = new node(6);

    node *root = new node(20);                                                      //test case 5
    root->left = new node(8);
    root->right = new node(22);
    root->left->left = new node(5);
    root->left->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(25);
    root->left->right->left = new node(10);
    root->left->right->right = new node(14);
    Print_lOT_lineBYLine(root);
    print_bottom_view(root);
    cout<<endl;
    //right_view_recursive(root);
}
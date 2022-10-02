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

int get_size(node *root)
{
    if(root==NULL)
        return 0;
    else
        return 1 + get_size(root->left) + get_size(root->right); 
}
// int get_size_itrative(node * root)
// {
//     if(root==NULL) return 0;
//     queue<node *>q;
//     q.push(root);
//     int count=1;
//     while(q.empty()==false)
//     {
//         node *cur=q.front();
//         q.pop();
//         if(cur->left!=NULL)
//         {
//             q.push(cur->left);
//             count++;                                                                     //both itrative soln are correct
//         }
//         if(cur->right!=NULL)
//         {
//             q.push(cur->right);
//             count++;
//         }
//     }
//     return count;
// }
int get_size_itrative(node * root)
{
    if(root==NULL) return 0;
    int count=0;
    queue<node *>q;
    q.push(root);
    while(q.empty()==false)
    {
        node *cur=q.front();
        q.pop();
        count++;
        if(cur->left!=NULL)
            q.push(cur->left);
        if(cur->right!=NULL)
            q.push(cur->right);
    }
    return count;
}
int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right=new node(30);
    Print_lOT_lineBYLine(root);
    cout<<"no. of nodes = "<<get_size(root)<<endl;
    cout<<"no. of nodes = "<<get_size_itrative(root);

}
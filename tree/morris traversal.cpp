#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vpi vector<pi>
#define vpll vector<pll>
#define sz(x) ((int)(x).size())
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define  uniq(a) a.resize(unique(a.begin(), a.end()) - a.begin());
#define all(x)      (x).begin(), (x).end()
#define inp(x) for(ll&i:x) cin>>i;
#define f(i,x,n) for(ll i=x;i<n;i++)
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
}; 
void inorder(Node *root)
{
    vector<int> in;
    Node *cur=root;
    while(cur!=NULL)
    {
        if(cur->left==NULL)
        {
            in.push_back(cur->data);
            cur=cur->right;
        }
        else
        {
            Node *pre=cur->left;
            while(pre->right and pre->right!=cur)
            pre=pre->right;
            if(pre->right==NULL)
            {
                pre->right=cur;
                cur=cur->left;
            }
            else
            {
                pre->right=NULL;
                in.push_back(cur->data);
                cur=cur->right;
            }
        }
    }
    for(int i=0;i<in.size();i++) cout<<in[i]<<" ";
}
void preorder(Node *root)
{
    vector<int> preor;
    Node *cur=root;
    while(cur!=NULL)
    {
        if(cur->left==NULL)
        {
            preor.push_back(cur->data);
            cur=cur->right;
        }
        else
        {
            Node *pre=cur->left;
            while(pre->right and pre->right!=cur)
            pre=pre->right;
            if(pre->right==NULL)
            {
                pre->right=cur;
                preor.push_back(cur->data);
                cur=cur->left;
            }
            else
            {
                pre->right=NULL;
                
                cur=cur->right;
            }
        }
    }
    for(int i=0;i<preor.size();i++) cout<<preor[i]<<" ";
}
int main()
{
    // space O(1)
    //TIME O(N)
Node *root=new Node(1);
root->left=new Node(2);
root->right=new Node(3);
root->left->left=new Node(4);
root->left->right=new Node(5);
inorder(root);
cout<<endl;
preorder(root);
return 0;
}
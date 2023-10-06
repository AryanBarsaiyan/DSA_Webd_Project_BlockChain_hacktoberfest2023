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
            key = x;
            left = right = NULL;
        }
};

unordered_map<int, int> indexMap;

node* Ctree(int in[], int po[], int is, int ie, int& postIndex)
{
    if (is > ie) return NULL;

    int rootValue = po[postIndex--];
    node* root = new node(rootValue);
    int inIndex = indexMap[rootValue];

    root->right = Ctree(in, po, inIndex + 1, ie, postIndex);
    root->left = Ctree(in, po, is, inIndex - 1, postIndex);

    return root;
}

node* buildTree(int in[], int po[], int n)
{
    int postIndex = n - 1;
    for (int i = 0; i < n; i++) {
        indexMap[in[i]] = i;
    }

    return Ctree(in, po, 0, n - 1, postIndex);
}

void printInorder(node* root)
{
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->key << " ";
    printInorder(root->right);
}

int main()
{
    int in[] = {5, 10, 12, 15, 18};
    int post[] = {5, 12, 18, 15, 10};
    int n = sizeof(in) / sizeof(in[0]);

    node* root = buildTree(in, post, n);
    printInorder(root);
    cout << endl;
    return 0;
}

#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
node *createBT()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root->left = createBT();
    root->right = createBT();
    return root;
}
void printatlevelK(node *root, int level, int k)
{
    if (!root)
        return;
    if (level == k)
    {
        cout << root->data << " ";
        return;
    }
    printatlevelK(root->left, level + 1, k);
    printatlevelK(root->right, level + 1, k);
}
int printatdistancek(node *root, int k, int target)
{
    // base case
    if (!root)
        return -1;

    // recursive case
    if (root->data == target)
    {
        printatlevelK(root, 0, k);
        return 0;
    }
    int DL = printatdistancek(root->left, k, target);
    if (DL != -1)
    {
        if (DL + 1 == k)
        {
            cout << root->data << " ";
            return -1;
        }
        else
        {
            printatlevelk(root->right, 0, k - DL - 2);
        }
        return DL + 1;
    }
    int DR = printatdistancek(root->right, k, target)

        if (DR != -1)
    {
        if (DR + 1 == k)
        {
            cout << root->data << " ";
            r
        }
        else
        {
            printatlevelK(root->left, 0, k - DR - 2);
        }
        return DR + 1;
    }
    return -1;
}
}
int main()
{
    node *root = createBT();
    printatdistancek(root, 2, 6);

    return 0;
}
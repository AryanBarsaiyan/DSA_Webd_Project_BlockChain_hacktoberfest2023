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
node *insertinBST(node *root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }
    // recursive case
    if (d <= root->data)
    {
        root->left = insertinBST(root->left, d);
    }
    else
    {
        root->right = insertinBST(root->right, d);
    }
    return root;
}
node *createBST()
{
    node *root = NULL;
    int d;
    cin >> d;
    while (d != -1)
    {
        root = insertinBST(root, d);
        cin >> d;
    }
    return root;
}
void preorde(node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    preorde(root->left);
    preorde(root->right);
}
void inorder(node *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
class LinkedList
{
public:
    node *head, *tail;
};
LinkedList BSTtoLL(node *root)
{
    LinkedList l;
    // base case
    if (!root)
    {
        l.head = l.tail = NULL;
    }
    // recursive case
    if (!root->left and !root->right)
    {
        l.head = l.tail = root;
        return l;
    }
    else if (!root->left and root->right)
    {
        LinkedList rightll = BSTtoLL(root->right);
        root->right = rightll.head;
        l.head = root;
        l.tail = rightll.tail;
        return l;
    }
    else if (root->left and !root->right)
    {
        LinkedList leftll = BSTtoLL(root->left);
        leftll.tail->right = root;
        l.head = leftll.head;
        l.tail = root;
        return l;
    }
    else
    {
        LinkedList leftll = BSTtoLL(root->left);
        LinkedList rightll = BSTtoLL(root->right);
        leftll.tail->right = root;
        root->right = rightll.head;
        l.head = leftll.head;
        l.tail = rightll.tail;
        return l;
    }
}
void printll(node *head)
{
    while (head)
    {
        cout << head->data << "-->";
        head = head->right;
    }
    cout << "NULL\n";
}

int main()
{
    node *root = NULL;
    root = createBST();
    // insertinBST(root, 9);
    cout << "pre:";
    preorde(root);
    cout << endl;
    cout << "inorder: ";
    inorder(root);
    cout << endl;
    LinkedList l = BSTtoLL(root);
    printll(l.head);
    return 0;
}
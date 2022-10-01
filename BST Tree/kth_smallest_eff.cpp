#include <iostream>
using namespace std;


class Node {

    public:

        int data;
        Node *left, *right;
        int lCount;
        Node(int x)
        {
            data = x;
            left = right = NULL;
            lCount = 0;
        }
};

Node* insert(Node* root, int x)
{
	if (root == NULL)
		return new Node(x);

	if (x < root->data) {
		root->left = insert(root->left, x);
		root->lCount++;
	}

	else if (x > root->data)
		root->right = insert(root->right, x);
	return root;
}

Node* kthSmallest(Node* root, int k)
{
	// base case
	if (root == NULL)
		return NULL;

	int count = root->lCount + 1;
	if (count == k)
		return root;

	if (count > k)
		return kthSmallest(root->left, k);

	return kthSmallest(root->right, k - count);
}

int main()
{
	Node* root = NULL;
	int keys[] = { 10,5,15,20,60};

	for (int x : keys)
		root = insert(root, x);

	Node* res = kthSmallest(root, 3);
	if (res == NULL)
		cout << "There are less than k nodes in the BST";
	else
		cout << "K-th Smallest Element is " << res->data;
	return 0;
}

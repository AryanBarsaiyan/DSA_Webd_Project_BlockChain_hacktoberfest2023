#include <bits/stdc++.h>
using namespace std;
struct node
{
           char data;
           int freq;
           node *left, *right;
           node(char data, int freq)
           {
                      left=NULL;
                      right=NULL;
                      this->data = data;
                      this->freq = freq;
           }
};
struct compare
 {
           bool operator()(node* left, node* right)
           {
                      return ((left->freq)>(right->freq));
           }
};
void print(node* root, string str)
{
           if(root==NULL)
                      return;
           if (root->data != '-')
                      cout<<root->data << ": " <<str<< "\n";
           print(root->left, str + "0");
           print(root->right, str + "1");
}
void codes(char data[], int freq[], int n)
{
           node *left, *right, *top;
           priority_queue<node*, vector<node*>, compare> min_heap;
           for (int i=0; i<n;i++)
                      min_heap.push(new node(data[i], freq[i]));
           while (min_heap.size() != 1)
           {
                      left = min_heap.top();
                      min_heap.pop();
                      right = min_heap.top();
                      min_heap.pop();
                      top = new node('-',(left->freq + right->freq));
                      top->left = left;
                      top->right = right;
                      min_heap.push(top);
           }
           cout<<"Required codes are:\n";
           print(min_heap.top(), "");
}
int main()
{
           char A[20];
           int freq[20],n;
           cout<<"Enter the number of characters:";
           cin>>n;
           cout<<"Enter the letters along with their frequencies:\n";
           for(int i=0;i<n;i++)
           {
                      cout<<i+1<<".Letter:";
                      cin>>A[i];
                      cout<<"  Frequency:";
                      cin>>freq[i];
           }
           codes(A,freq,n);
           return 0;
}

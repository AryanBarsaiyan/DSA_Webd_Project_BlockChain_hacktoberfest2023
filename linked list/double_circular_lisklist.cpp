#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node * next;
        node * prev;
        node(int x)
        {
            data=x;
            next=NULL;
            prev=NULL;
        }
};
void create_list(node * &head)
{
    int n,x;
    cout<<"Enter the no. of element you want to insert"<<endl;
    cin>>n;
    cout<<"Enter the elements"<<endl;
    cin>>x;
    head=new node(x);
    node *temp=head;
    for(int i=2;i<=n;i++)
    {
        cin>>x;
        node *new_node=new node(x);
        temp->next=new_node;
        new_node->prev=temp;
        temp=temp->next;
    }
    temp->next=head;
    head->prev=temp;
}
void insert_beg(node * &head,int x)
{
    if(head==NULL)
    {
        head=new node(x);
        head->next=head;
        head->prev=head;
    }
    else{
        node *new_node=new node(x);
        new_node->next=head;
        new_node->prev=head->prev;
        head->prev->next=new_node;
        head->prev=new_node;
        head=new_node;
    }

}
void print_list(node *head)
{
    if(head==NULL) return;
    node *temp=head;
    cout<<temp->data<<"->";
    for(temp=temp->next;temp!=head;temp=temp->next)
            cout<<temp->data<<"->";
}
int main()
{
    node *head;
    create_list(head);
    insert_beg(head,1);
    print_list(head);
}
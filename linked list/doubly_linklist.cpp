#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node *next;
        node *prev;
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
    cout<<"no. of element in the list"<<endl;
    cin>>n;
    cout<<"enter the elements"<<endl;
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
}
void print_list(node * head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }  
    cout<<"NULL"<<endl; 
}
void insert_beg(node * &head,int x)
{
    if(head==NULL)
        head=new node(x);
    else{
        node * new_node=new node(x);
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
    }
}
void insert_at_end(node * &head,int x)
{
    if(head==NULL)
        head=new node(x);
    else{
        node *temp =head;
        while(temp->next!=NULL)
            temp = temp->next;
        node * new_node=new node(x);
        temp->next=new_node;
        new_node->prev=temp;
    }
}
node* reversedll(node* head)
{
    if(head->next==NULL && head->next==NULL)
        return head;
    node *pre=NULL, *cur=head;
    while(cur!=NULL)
    {
        pre=cur->prev;
        cur->prev=cur->next;
        cur->next=pre;
        cur=cur->prev;
    }
    return pre->prev;
}
void delete_head(node* &head)
{
    if(head==NULL)
        return;
    node *temp=head;
    head=head->next;
    head->prev=NULL;
    delete(temp);
}
void delete_last_node(node *head)
{
    if(head==NULL){
        cout<<"delete not possible"<<endl;  return;}
    node* temp=head;
    if(head->next==NULL)
    {
        head=NULL;
        delete(temp);
    }
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node *temp1=temp->next;
    temp->next=NULL;
    delete(temp1);
}
int main()
{
    node *head;
    create_list(head);
    //insert_beg(head,1);
    //insert_at_end(head,111);
    print_list(head);
   // head=reversedll(head);
    delete_head(head);
    print_list(head);
    delete_last_node(head);
    print_list(head);
}
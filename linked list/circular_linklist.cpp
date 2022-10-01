#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node* next;
        node(int x)
        {
            data=x;
            next=NULL;
        }
};
void create_list(node * &head)
{
    int n,x;
    cout<<"Enter the no. of element for yr list"<<endl;
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
        temp=temp->next;
    }
    temp->next=head;
}
void printlist1_(node *head)
{
    if(head==NULL) return;
        cout<<head->data<<"  ";
    for(node *p=head->next;p!=head;p=p->next)
        cout<<p->data<<"  ";
    cout<<endl;
}
void printlist2_(node *head)
{
    if(head==NULL) return ;
    node *p=head;
    do{
        cout<<p->data<<"  ";
        p=p->next;
    }while(p!=head);
    cout<<endl;
}
void insert_beg(node * &head,int x)
{
    node *temp=head;
    node *new_node=new node(x);
    if(head==NULL)
    {
        head=new_node;
        head->next=head;
    }
    else{
        new_node->next=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=new_node;
        head=new_node;
    }
}
void insert_beg_efficient(node* &head,int x)
{
    node *new_node=new node(x);
    if(head==NULL)
    {
        head=new_node;
        head->next=head;
    }
    else
    {
        new_node->next=head->next;
        head->next=new_node;
        int t=head->data;
        head->data=new_node->data;
        new_node->data=t;
    }
}
void insert_end(node * &head,int x)
{
    node *temp=head;
    node *new_node=new node(x);
    if(head==NULL)
    {
        head=new_node;
        head->next=head;
    }
    else{
        new_node->next=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=new_node;
       // head=new_node;
    }
}
void insert_end_efficient(node* &head,int x)
{
    node *new_node=new node(x);
    if(head==NULL)
    {
        head=new_node;
        head->next=head;
    }
    else
    {
        new_node->next=head->next;
        head->next=new_node;
        int t=head->data;
        head->data=new_node->data;
        new_node->data=t;
        head=head->next;
    }
}
void delete_head(node * &head)
{
    if(head==NULL) return;
    else
    {
        node *temp=head;
        while(temp->next!=head)
            temp=temp->next;
        node*temp1=head;
        head=head->next;
        temp->next=head;
        delete(temp1);
    }
}
void delete_head_efficient(node * &head)
{
    if(head==NULL) return ;
    else
    {
        head->data=head->next->data;
        node *temp=head->next;
        head->next=head->next->next;
    }
}
void delete_kth_node(node * &head,int k)
{
    if(head==NULL) return;
    else if(k==1)    delete_head_efficient(head);
    else{
        node *temp=head;
        for(int i=0;i<k-2;i++)
            temp=temp->next;
        node *temp1=temp->next;
        temp->next=temp->next->next;
        delete(temp1);
    }
}

int main()
{
    node *head;
    create_list(head);
    // printlist2_(head);
    // insert_beg(head,1);
    // printlist1_(head);
    // insert_beg_efficient(head,0);
    // printlist1_(head);
    // insert_end_efficient(head,7);
    // printlist1_(head);
    // insert_end(head,8);
    //delete_head(head);
    //delete_head_efficient(head);
    delete_kth_node(head,3);
    printlist1_(head);
    return 0;
}
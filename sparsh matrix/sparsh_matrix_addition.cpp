#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int row;
    int col;
    int value;
    node *next;
    node(int x, int y,int z)
    {
        row=x;
        col=y;
        value=z;
        next=NULL;
    }
};
void createsparse(node * &head)
{
    cout<<"enter the no. of data element"<<endl;
    int n;
    cin>>n;
    cout<<"enter the data element as row column vaule"<<endl;
    int r,c,v;
    cin>>r>>c>>v;
    head=new node(r,c,v);
    node *temp=head;
    for(int i=2;i<=n;i++)
    {
        cin>>r>>c>>v;
        node *new_node=new node(r,c,v);
        temp->next=new_node;
        temp=temp->next;
    }
}
void printsparse(node *head)
{
    if(head==NULL)
    {   
        return;
    }
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->row<<" "<<temp->col<<" "<<temp->value<<" , ";
        temp=temp->next;
    }
    cout<<endl;
}
void Insert(node * &head,int r,int c,int v)
{
    if(head==NULL)
    {
        head=new node(r,c,v);
        return;
    }
    node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    node *new_node=new node(r,c,v);
    temp->next=new_node;
    temp=temp->next;
}
void sum(node * &head,node *a,node *b)
{
    while(a!=NULL && b!=NULL)
    {
        if(a->row == b->row)
        {
            if(a->col == b->col)
            {
                Insert(head,a->row,a->col,a->value + b->value);
                a=a->next;
                b=b->next;
            }
            else if(a->col < b->col)
            {
                Insert(head,a->row,a->col,a->value);
                a=a->next;
            }
            else{
                Insert(head,b->row,b->col,b->value);
                b=b->next;
            }
        }
        else if(a->row < b->row)
        {
            Insert(head,a->row,a->col,a->value);
            a=a->next;
        }
        else
        {
            Insert(head,b->row,b->col,b->value);
            b=b->next;
        }
    }
    while(a!=NULL)
    {
        Insert(head,a->row,a->col,a->value);
        a=a->next;
    }
    while(b!=NULL)
    {
        Insert(head,b->row,b->col,b->value);
        b=b->next;
    }
}
int main()
{
    node *a,*b,*c=NULL;
    createsparse(a);
    cout<<"a matrix =";
    printsparse(a);
    createsparse(b);
   cout<<"b matrix =";
    printsparse(b);
    sum(c,a,b);
    cout<<"sum matric =";
    printsparse(c);
}
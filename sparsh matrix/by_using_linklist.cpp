#include<iostream>
using namespace std;
class node
{
    public:
        int row;
        int column;
        int value;
        node *next;
    node(int i,int j,int val)
    {
        row=i;
        column=j;
        value=val;
        next=NULL;
    }
};
void create_node(node * &head,int i,int j,int val)
{
    if(head==NULL)
    {
        head=new node(i,j,val);
    }
    else
    {
        node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        node *newnode=new node(i,j,val);
        temp->next=newnode;
    }
}
void print_list(node * &head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->row<<" ";
        temp=temp->next;
    }
    cout<<endl;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->column<<" ";
        temp=temp->next;
    }
    cout<<endl;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->value<<" ";
        temp=temp->next;
    }
}
int main()
{
    int sparseMatrix[4][5] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };
    node *head=NULL;
    for(int i=0;i<4;i++)
        for(int j=0;j<5;j++)
            if(sparseMatrix[i][j]!=0)
            {
                create_node(head,i,j,sparseMatrix[i][j]);
            }
    print_list(head);
}
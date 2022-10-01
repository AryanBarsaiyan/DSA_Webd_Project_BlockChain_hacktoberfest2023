#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node *next;
        node(int x)
        {
            data=x;
            next=NULL;
        }
};
void push(node** head_ref, int new_data)
{
    /* allocate node */
    node* new_node = new node(new_data);
 
    /* put in the data  */
    
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
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
void detect_loop(node *head)
{
    node *slowp=head;
    node *fastp=head;
    while(fastp!=NULL || fastp->next!=NULL)
    {
        slowp=slowp->next;
        fastp=fastp->next->next;
        if(fastp==slowp){
            cout<<"loop exist "<<endl;;
            return ;
        }
    }
    cout<<"loop not found"<<endl;
}
int main()
{
    node *head;
   
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    head->next->next->next->next = head;
    printlist2_(head);
    detect_loop(head);

}
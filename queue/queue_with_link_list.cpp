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
class queue
{
    public:
            node *front;
            node *rear;
            int size;
            queue()
            {
                front=NULL;
                rear=NULL;
                size=0;
            }

            void push(int x)
            {
                if(front==NULL)
                {
                    front=new node(x);
                    rear=front;
                    size++;
                }
                else
                {
                    node *new_node=new node(x);
                    rear->next=new_node;
                    rear=rear->next;
                    size++;
                }
            }

            void pop()
            {
                if(front==NULL)
                {
                    cout<<"queue underflow"<<endl;
                    return;
                }
                else if(front->next==NULL)
                {
                    node *temp=front;
                    front=NULL;
                    rear=NULL;
                    delete(temp);
                    size--;
                }
                else{
                    node *temp=front;
                    front=front->next;
                    delete(temp);
                    size--;
                }
            }

            int get_front()
            {
                if(front==NULL)
                {
                    cout<<"queue is empty"<<endl;
                    return -99999;
                }
                return front->data;
            }

            int get_rear()
            {
                if(front==NULL)
                {
                    cout<<"queue is empty"<<endl;
                    return -99999;
                }
                return rear->data;
            }

            int Size()
            {
                return size;
            }
};
int main()
{
    queue q;
    //q.get_rear();
    q.push(2);
    cout<<q.get_front()<<endl;
    q.push(4);
    cout<<q.get_rear()<<endl;
    q.push(6);
    cout<<q.get_rear()<<endl;
    q.push(8);
    cout<<q.get_rear()<<endl;
    q.push(10);
    cout<<q.get_rear()<<endl;
    cout<<"size:"<<q.Size()<<endl;
    q.pop();
    cout<<q.get_front()<<endl;
    cout<<"size:"<<q.Size()<<endl;
}
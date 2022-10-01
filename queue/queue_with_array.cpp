 #include<iostream>
using namespace std;
class Myqueue
{
    public:
        int front,rear,cap;
        int *arr;
        Myqueue(int x)
        {
            front=-1;
            rear=-1;
            cap=x;
            arr=new int[cap];
        }

        void push(int x)
        {
            if(front==-1)
            {
                front++;
                rear++;
                arr[rear]=x;
            }
            else if((rear+1)%cap==front)
            {
                cout<<"queue overflow"<<endl;
                return;
            }
            else{
                rear++;
                rear=rear%cap;
                arr[rear]=x;
            }
        }
        void pop()
        {
            if(rear==-1)
            {
                cout<<"queue underflow"<<endl;
                return;
            }
            else if(front==rear)
            {
                front=-1;
                rear=-1;
            }
            else{
                front++;
                front=front%cap;
            }
        }

        int get_rear()
        {
            if(rear==-1)
            {
                cout<<"queue is empty"<<endl;
                return 99999;
            }
            else
                return arr[rear];
        }

        int get_front()
        {
            if(front==-1)
            {
                cout<<"queue is empty"<<endl;
                return 99999;
            }
            else
                return arr[front];
        }
        bool is_full()
        {
            return ((rear+1)%cap==front); 
        }

        bool is_empty()
        {
            return (front==-1);
        }
};
int main()
{
    Myqueue s(5);
    cout<<s.is_empty()<<endl;
    s.push(2);
    cout<<s.get_front()<<endl;
    s.push(4);
    cout<<s.get_rear()<<endl;
    s.push(6);
    cout<<s.get_rear()<<endl;
    s.push(8);
    cout<<s.get_rear()<<endl;
    s.push(10);
    cout<<s.get_rear()<<endl;
    s.pop();
    cout<<s.get_front()<<endl;
    s.push(20);
    cout<<s.get_rear()<<endl;
    cout<<s.is_full()<<endl;
}
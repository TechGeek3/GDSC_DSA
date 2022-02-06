//Implement a Queue using Linked List. 
//A Query Q is of 2 Types
//(i) 1 x   (a query of this type means  pushing 'x' into the queue)
//(ii) 2     (a query of this type means to pop an element from the queue and print the poped element)

#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyQueue *sq = new MyQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
    }

/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

void MyQueue:: push(int x)                                 //Function to push an element into the queue.
{
    QueueNode *temp = new QueueNode(x);
    
    if(front == NULL)
    {
        front = rear = temp;
        return;    
    }
    
    rear->next = temp;
    rear = temp;
    rear->next = NULL;
        
}

int MyQueue :: pop()                                    //Function to pop front element from the queue.
{
    if(front == NULL)
        return -1;
        
    int ele = front->data;
    front = front->next;
    return ele;
}
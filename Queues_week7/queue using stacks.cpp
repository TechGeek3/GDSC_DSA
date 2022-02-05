//Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions 
//of a normal queue (push, peek, pop, and empty).

//Implement the MyQueue class:

//void push(int x) Pushes element x to the back of the queue.
//int pop() Removes the element from the front of the queue and returns it.
//int peek() Returns the element at the front of the queue.
//boolean empty() Returns true if the queue is empty, false otherwise.

class MyQueue {
public:
    stack<int> st_main;
    stack<int> st_aux;
    
    MyQueue() {
        
    }
    
    void push(int x) {                 
        while(!st_main.empty())                    //empty main and add them to aux
        {
            st_aux.push(st_main.top());
            st_main.pop();
        } 
        st_aux.push(x);                            //push the element to be pushed in queue
        while(!st_aux.empty())                     //empty the aux and push elements in main
        {
            st_main.push(st_aux.top());
            st_aux.pop();
        }
    }
    
    int pop() {
        int front = st_main.top();
        st_main.pop();
        return front;
    }
    
    int peek() {
        return st_main.top();
    }
    
    bool empty() {
        if(st_main.empty())
            return true;
        
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
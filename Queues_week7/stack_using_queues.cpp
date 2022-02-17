//Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions 
//of a normal stack (push, top, pop, and empty).

//Implement the MyStack class:

//void push(int x) Pushes element x to the top of the stack.
//int pop() Removes the element on the top of the stack and returns it.
//int top() Returns the element on the top of the stack.
//boolean empty() Returns true if the stack is empty, false otherwise.

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    int peek = 0;
    MyStack() {
        
    }
    
    void push(int x) {                        //O(1)
        q1.push(x);
        peek = x;                             //according to stack the one which is pushed is at the top
    }
    
    int pop() {                               //O(n)
        while(q1.size() != 1)                 //element to be popped is present at the rare end of q1
        {                                     //empty the queue by shifting it in q2(except element to be popped)
            peek = q1.front();
            q2.push(peek);                    //Again shift them in q1
            q1.pop();
        }
        int ele = q1.front();
        q1.pop();
        
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        
        return ele;
    }
    
    int top() {
        return peek;
    }
    
    bool empty() {
        if(q1.empty())
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

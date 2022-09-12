class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        // Maintain the newly pushed element at the bottom of the stack
        // so that the top of the stack always work like the font of the queue
        while(!major_stack.empty()){
            minor_stack.push(major_stack.top());
            major_stack.pop();
        }
        
        major_stack.push(x);
        
        while(!minor_stack.empty()){
            major_stack.push(minor_stack.top());
            minor_stack.pop();
        }
    }
    
    int pop() {
        temp = major_stack.top();
        major_stack.pop();
        return temp;
    }
    
    int peek() {
        return major_stack.top();
    }
    
    bool empty() {
        return major_stack.empty();
    }
    
private:
    stack<int> major_stack;
    stack<int> minor_stack;
    int temp;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
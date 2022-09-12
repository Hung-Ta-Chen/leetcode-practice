class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        
        // Whenever a new element is pushed, adjust it to the front of the queue 
        // so that the front of the queue indicates the top of the stack
        for(int i = 0; i < q1.size()-1; i++){
            temp = q1.front();
            q1.pop();
            q1.push(temp);
        }
    }
    
    int pop() {
        temp = q1.front();
        q1.pop();
        
        return temp;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
private:
    queue<int> q1;
    int temp;
 };

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
class MinStack {
public:
    stack<int> minStack;
    stack<int> minElement;

    MinStack() {
        
    }
    
    void push(int val) {
        minStack.push(val);
        if (minElement.empty() || val <= minElement.top()){
            minElement.push(val);
        }
    }
    
    void pop() {
        int a = minStack.top();
        minStack.pop();
        if (minElement.top() == a){
            minElement.pop();
        }
    }
    
    int top() {
        int top = minStack.top();
        return top;
    }
    
    int getMin() {
        return minElement.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
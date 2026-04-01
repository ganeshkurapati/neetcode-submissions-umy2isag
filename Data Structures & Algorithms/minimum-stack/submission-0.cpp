class MinStack {
    stack<int> S;
    stack<int> min_stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        S.push(val);
        int min_val = min(val, min_stack.empty()? val : min_stack.top());
        min_stack.push(min_val);
    }
    
    void pop() {
        S.pop();
        min_stack.pop();
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

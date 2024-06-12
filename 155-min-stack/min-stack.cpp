

class MinStack {
public:
    stack<int> mainStack;
    stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top())
            minStack.push(val);
    }
    
    void pop() {
        if (mainStack.top() == minStack.top())
            minStack.pop();
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

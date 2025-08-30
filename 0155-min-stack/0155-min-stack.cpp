class MinStack {
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        mini=1e15;
    }
    
    void push(int val) {
        if(val>=mini) st.push(val);
        else{
            long long newVal=2*1LL*val-mini;
            mini=val;
            st.push(newVal);
        }
    }
    
    void pop() {
        if(st.top()>=mini) st.pop();
        else{
            mini=2*mini-st.top();
            st.pop();
        }
    }
    
    int top() {
        if(mini<=st.top()) return st.top();
        else return mini;
    }
    
    int getMin() {
        return mini;
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
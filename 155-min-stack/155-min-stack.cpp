class MinStack {
stack<int> st , temp; 
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(temp.size()==0 || temp.top()>=val){
            temp.push(val);
            return;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        int a = st.top();
        st.pop();
        
        if(temp.top()==a) temp.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        return temp.top();
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
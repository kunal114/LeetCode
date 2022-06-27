class MyStack {
queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        int s = q.size();
        for(int i=1;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(q.empty()) return -1;
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        if(q.empty()) return -1;
        int top = q.front();
        return top;
    }
    
    bool empty() {
        if(q.empty()) return true;
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
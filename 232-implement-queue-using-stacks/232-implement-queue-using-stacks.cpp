class MyQueue {
    
stack<int> st;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(!st.size()) {
            st.push(x);
            return;
        }
        int data = st.top();
        st.pop();
        
        push(x);
        st.push(data);
    }
    
    int pop() {
        int ans = st.top();
        st.pop();
        return ans;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
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
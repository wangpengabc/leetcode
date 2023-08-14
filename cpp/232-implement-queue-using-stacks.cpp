// https://leetcode.cn/problems/implement-queue-using-stacks/


class MyQueue {
public:
    stack<int> s_in;
    stack<int> s_out;

    MyQueue() {
    }
    
    void push(int x) {
        s_in.push(x);
    }
    
    int pop() {
        while (!s_in.empty()) {
            int top = s_in.top();
            s_out.push(top);
            s_in.pop();
        }
        int ret = s_out.top();
        s_out.pop();
        while (!s_out.empty()) {
            int top = s_out.top();
            s_in.push(top);
            s_out.pop();
        }
        return ret;
    }
    
    int peek() {
        while (!s_in.empty()) {
            int top = s_in.top();
            s_out.push(top);
            s_in.pop();
        }
        int ret = s_out.top();
        while (!s_out.empty()) {
            int top = s_out.top();
            s_in.push(top);
            s_out.pop();
        }
        return ret;
    }
    
    bool empty() {
        return s_in.empty() && s_out.empty();
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

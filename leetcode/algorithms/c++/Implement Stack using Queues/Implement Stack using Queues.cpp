class MyStack
{
private:
    stack<int> base;

public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        base.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int result = top();
        base.pop();
        return result;
    }

    /** Get the top element. */
    int top()
    {
        return base.top();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return base.empty();
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
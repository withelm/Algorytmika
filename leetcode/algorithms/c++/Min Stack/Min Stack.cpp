class MinStack
{
private:
    stack<int> st;
    stack<int> minimum;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        int v = x;
        if (!minimum.empty())
            v = min(v, getMin());
        st.push(x);
        minimum.push(v);
    }

    void pop()
    {

        st.pop();
        minimum.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minimum.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
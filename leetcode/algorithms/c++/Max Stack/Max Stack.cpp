class MaxStack
{
private:
    vector<int> s;

public:
    /** initialize your data structure here. */
    MaxStack()
    {
    }

    void push(int x)
    {
        s.push_back(x);
    }

    int pop()
    {
        int v = s.back();
        s.pop_back();
        return v;
    }

    int top()
    {
        return s.back();
    }

    int peekMax()
    {
        int v = s[0];
        int id = 0;
        int n = s.size();
        for (int i = 1; i < n; i++)
        {
            if (v <= s[i])
            {
                v = s[i];
                id = i;
            }
        }

        return v;
    }

    int popMax()
    {
        int v = s[0];
        int id = 0;
        int n = s.size();
        for (int i = 1; i < n; i++)
        {
            if (v <= s[i])
            {
                v = s[i];
                id = i;
            }
        }
        s.erase(s.begin() + id);
        return v;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
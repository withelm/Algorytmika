class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> k;
        int n = pushed.size();
        int pop_index = 0;
        for (int i = 0; i < n; i++)
        {
            k.push(pushed[i]);
            while (!k.empty() && pop_index < n && k.top() == popped[pop_index])
            {
                ++pop_index;
                k.pop();
            }
        }
        return k.empty() && pop_index == n;
    }
};
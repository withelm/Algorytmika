class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        stack<string> st;
        for (auto &x : logs)
        {
            if (x == "./")
                continue;
            if (x == "../")
            {
                if (!st.empty())
                    st.pop();
                continue;
            }
            st.push(x);
        }
        return st.size();
    }
};
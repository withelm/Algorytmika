class Solution
{
private:
    stack<int> st;

public:
    int evalRPN(vector<string> &tokens)
    {
        for (auto &item : tokens)
        {
            if (item[0] == '+')
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a + b);
            }
            else if (item[0] == '-' && item.size() == 1)
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            }
            else if (item[0] == '*')
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a * b);
            }
            else if (item[0] == '/')
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b / a);
            }
            else
            {
                st.push(stoi(item));
            }
        }
        return st.top();
    }
};
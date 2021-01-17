class Solution
{
public:
    int calculate(string s)
    {

        int begin = 0;
        int n = s.size();
        stack<int> st;
        int div = 0;
        bool isDiv = false;
        bool isMinus = false;
        int val = 0;
        char zn = '+';
        vector<int> ops;

        while (begin < n)
        {

            while (begin < n && s[begin] == ' ')
                ++begin;
            while (begin < n && s[begin] >= '0' && s[begin] <= '9')
            {
                val = val * 10 + (s[begin] - '0');
                ++begin;
            }
            while (begin < n && s[begin] == ' ')
            {
                ++begin;
            }

            if (zn == '+')
            {
                st.push(val);
            }
            else if (zn == '-')
            {
                st.push(-val);
            }
            else if (zn == '*')
            {
                int prev = st.top();
                st.pop();
                st.push(prev * val);
            }
            else if (zn == '/')
            {
                int prev = st.top();
                st.pop();
                st.push(prev / val);
            }
            zn = s[begin];
            val = 0;
            ++begin;
        }
        int r = 0;
        while (!st.empty())
        {
            r += st.top();
            st.pop();
        }
        return r;
    }
};
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        vector<int> t;

        int r = -1;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                int tmp = 0;
                int index = i;
                while (index < n && tmp >= 0)
                {
                    if (s[index] == '(')
                        ++tmp;
                    else
                        --tmp;
                    if (tmp == 0)
                        r = max(r, index - i);
                    ++index;
                }
            }
        }
        return r + 1;
    }
};
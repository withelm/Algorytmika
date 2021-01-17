class Solution
{
private:
    stack<char> st;

public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();

        if (n <= k)
            return "0";

        while (!st.empty())
            st.pop();

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && k > 0 && num[i] < st.top())
            {
                st.pop();
                --k;
            }
            st.push(num[i]);
        }
        while (k > 0 && !st.empty())
        {
            --k;
            st.pop();
        }
        string answer;
        while (!st.empty())
        {
            answer.push_back(st.top());
            st.pop();
        }
        reverse(answer.begin(), answer.end());
        int index = 0;
        while (index < answer.size() && answer[index] == '0')
        {
            ++index;
        }
        if (index == answer.size())
            return "0";
        answer.erase(0, index);
        return answer;
    }
};
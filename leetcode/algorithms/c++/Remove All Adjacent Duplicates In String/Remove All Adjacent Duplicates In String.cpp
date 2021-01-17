class Solution
{
public:
    string removeDuplicates(string S)
    {
        stack<char> s;
        for (auto &x : S)
        {
            int counter = 0;
            while (!s.empty() && s.top() == x)
            {
                s.pop();
                ++counter;
            }
            if (counter == 0)
            {
                s.push(x);
            }
        }
        string r = "";
        while (!s.empty())
        {
            r += s.top();
            s.pop();
        }
        reverse(r.begin(), r.end());
        return r;
    }
};
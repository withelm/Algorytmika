class Solution
{
public:
    vector<string> generatePossibleNextMoves(string s)
    {
        vector<string> r;
        int n = s.size();
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] == '+' && s[i] == '+')
            {
                r.push_back(s);
                r.back()[i] = r.back()[i - 1] = '-';
            }
        }
        return r;
    }
};
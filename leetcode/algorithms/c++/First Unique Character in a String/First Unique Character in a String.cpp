class Solution
{
public:
    int firstUniqChar(string s)
    {
        map<char, vector<int>> base;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            base[s[i]].push_back(i);
        }
        int result = n + 1;
        for (auto &x : base)
        {
            if (x.second.size() == 1)
            {
                result = min(result, x.second[0]);
            }
        }
        if (result == n + 1)
            return -1;
        return result;
    }
};
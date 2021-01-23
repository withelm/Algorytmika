class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        map<char, vector<int>> base;
        int r = -1;
        for (int i = 0; i < s.size(); i++)
        {
            base[s[i]].push_back(i);
            if (base[s[i]].size() > 1)
            {
                r = max(r, base[s[i]].back() - base[s[i]][0] - 1);
            }
        }
        return r;
    }
};
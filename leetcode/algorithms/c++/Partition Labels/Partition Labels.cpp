class Solution
{
private:
    bool check(set<char> &c, int i, string &S)
    {
        for (auto x : c)
        {
            for (int j = i + 1; j < S.size(); j++)
            {
                if (S[j] == x)
                    return false;
            }
        }
        return true;
    }

public:
    vector<int> partitionLabels(string S)
    {
        vector<int> result;
        int n = S.size();
        set<char> c;
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            c.insert(S[i]);
            ++m;
            if (check(c, i, S))
            {
                result.push_back(m);
                c.clear();
                m = 0;
            }
        }
        return result;
    }
};
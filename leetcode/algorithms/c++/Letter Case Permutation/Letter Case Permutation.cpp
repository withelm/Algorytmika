class Solution
{
private:
    string tolower(string &x)
    {
        for (auto &i : x)
            if (i >= 'A' && i <= 'Z')
                i = i - 'A' + 'a';
        return x;
    }

public:
    vector<string> letterCasePermutation(string S, int index = 0)
    {
        set<string> r;
        S = tolower(S);
        int n = S.size();
        for (int i = 0; i < (1 << n); i++)
        {
            S = tolower(S);
            for (int j = 0; j < n; j++)
            {
                if (S[j] >= 'a' && S[j] <= 'z')
                {
                    if (i & (1 << j))
                    {
                        S[j] = S[j] - 'a' + 'A';
                    }
                    else
                    {
                        S[j] = S[j];
                    }
                }
            }
            r.insert(S);
        }
        vector<string> result;
        for (auto &x : r)
            result.push_back(x);
        return result;
    }
};
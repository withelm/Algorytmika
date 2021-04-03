class Solution
{
public:
    vector<int> movesToStamp(string stamp, string t)
    {
        int n = t.size();
        int m = stamp.size();
        vector<int> result;
        bool isReplace = false;
        while (true)
        {
            for (int i = 0; i < n; i++)
            {
                int cnt_hash = 0;
                bool full_word = true;
                for (int j = 0; j < m; j++)
                {
                    if (t[i + j] == '#')
                    {
                        ++cnt_hash;
                    }
                    else if (t[i + j] != stamp[j])
                    {
                        full_word = false;
                        break;
                    }
                }
                if (full_word && cnt_hash < m)
                {
                    for (int j = i; j < i + m; j++)
                        t[j] = '#';
                    result.push_back(i);
                    isReplace = true;
                }
            }
            if (!isReplace)
                break;
            isReplace = false;
        }
        for (auto &x : t)
            if (x != '#')
                return {};
        reverse(result.begin(), result.end());
        return result;
    }
};
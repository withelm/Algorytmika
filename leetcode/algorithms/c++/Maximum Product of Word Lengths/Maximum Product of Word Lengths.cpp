class Solution
{
private:
    map<string, int> kub;

    bool check(string &x, string &y)
    {
        return (kub[x] & kub[y]) == 0;
    }

public:
    int maxProduct(vector<string> &words)
    {
        for (auto &word : words)
        {
            int val = 0;
            for (auto &i : word)
            {
                val |= (1 << (i - 'a'));
            }
            kub[word] = val;
        }

        int result = 0;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (check(words[i], words[j]))
                {
                    result = max(result, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return result;
    }
};
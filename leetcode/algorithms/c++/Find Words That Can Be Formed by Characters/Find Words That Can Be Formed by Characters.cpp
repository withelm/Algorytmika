class Solution
{
private:
    int MX = 300;
    vector<int> generateKub(string &x)
    {
        vector<int> kub(MX, 0);
        for (auto &i : x)
            ++kub[i];
        return kub;
    }
    bool check(vector<int> &x, vector<int> &y)
    {
        for (int i = 0; i < MX; i++)
        {
            if (y[i] > x[i])
                return false;
        }
        return true;
    }

public:
    int countCharacters(vector<string> &words, string chars)
    {
        vector<int> kub(MX, 0);
        for (auto &x : chars)
            ++kub[x];
        int result = 0;
        for (auto &x : words)
        {
            auto kubX = generateKub(x);
            if (check(kub, kubX))
            {
                result += x.size();
            }
        }
        return result;
    }
};
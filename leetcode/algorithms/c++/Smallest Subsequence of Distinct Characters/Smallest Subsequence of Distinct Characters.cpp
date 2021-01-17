class Solution
{
public:
    string smallestSubsequence(string s)
    {
        vector<int> kub(300, 0);
        vector<int> used(300, false);

        for (auto &x : s)
            ++kub[x];
        string result = "";

        for (auto &x : s)
        {
            --kub[x];
            if (used[x])
                continue;
            while (result.size() > 0 && x < result.back() && kub[result.back()] > 0)
            {
                used[result.back()] = false;
                result.pop_back();
            }
            result += x;
            used[x] = true;
        }

        return result;
    }
};
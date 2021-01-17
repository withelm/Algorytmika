class Solution
{
private:
public:
    string sortString(string s)
    {
        vector<int> kub(300, 0);
        for (auto &x : s)
        {
            ++kub[x];
        }
        string result = "";
        while (result.size() < s.size())
        {
            for (int i = 'a'; i <= 'z'; i++)
            {
                if (kub[i] > 0)
                {
                    result.push_back(i);
                    --kub[i];
                }
            }
            for (int i = 'z'; i >= 'a'; i--)
            {
                if (kub[i] > 0)
                {
                    result.push_back(i);
                    --kub[i];
                }
            }
        }
        return result;
    }
};
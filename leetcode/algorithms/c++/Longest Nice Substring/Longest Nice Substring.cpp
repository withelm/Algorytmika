class Solution
{
private:
    bool check(string x)
    {
        map<char, int> base;
        for (auto &i : x)
            base[i]++;
        for (char i = 'a'; i <= 'z'; i++)
            if (base[i] > 0 && base[(i - 'a') + 'A'] == 0)
                return false;
        for (char i = 'A'; i <= 'Z'; i++)
            if (base[i] > 0 && base[(i - 'A') + 'a'] == 0)
                return false;
        return true;
    }

public:
    string longestNiceSubstring(string s)
    {
        int n = s.size();
        string r = "";

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n - i + 1; j++)
            {
                if (check(s.substr(i, j)))
                {
                    if (r.size() < s.substr(i, j).size())
                        r = s.substr(i, j);
                }
            }
        }
        return r;
    }
};
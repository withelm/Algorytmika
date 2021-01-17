class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        int n = s.size();
        int r = 0;

        vector<char> spr = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        for (int i = 0; i < n / 2; i++)
        {
            for (auto &x : spr)
                r += x == s[i];
        }

        for (int i = n / 2; i < n; i++)
            for (auto &x : spr)
                r -= x == s[i];

        return r == 0;
    }
};
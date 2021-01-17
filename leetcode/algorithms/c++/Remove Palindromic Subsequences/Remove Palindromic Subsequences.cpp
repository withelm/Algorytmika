class Solution
{
public:
    int removePalindromeSub(string s)
    {
        int n = s.size();
        bool isPal = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != s[n - i - 1])
                isPal = false;
        }
        if (s.size() == 0)
            return 0;
        if (isPal)
            return 1;
        return 2;
    }
};
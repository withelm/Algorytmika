class Solution
{
private:
    bool check(string &s, int x, int n)
    {
        for (int i = x; i < n; i++)
        {
            if (s[i] != s[i % x])
                return false;
        }
        return true;
    }

public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.size();
        if (n == 1)
            return false;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (check(s, i, n))
                    return true;
                if (n / i != n && check(s, n / i, n))
                    return true;
            }
        }
        return false;
    }
};
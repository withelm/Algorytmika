class Solution
{
private:
    string normalizeString(string s)
    {
        string result = "";
        for (auto &x : s)
        {
            if (x >= 'A' && x <= 'Z')
                result += x - 'A' + 'a';
            if (x >= 'a' && x <= 'z')
                result += x;
            if (x >= '0' && x <= '9')
                result += x;
        }
        return result;
    }

public:
    bool isPalindrome(string s)
    {
        string x = normalizeString(s);
        int n = x.size();
        for (int i = 0; i < n; i++)
        {
            if (x[i] != x[n - i - 1])
                return false;
        }
        return true;
    }
};
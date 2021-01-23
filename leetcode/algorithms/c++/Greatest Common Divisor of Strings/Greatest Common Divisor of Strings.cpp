class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1.size() > str2.size())
            swap(str1, str2);

        int n = str1.size();
        int m = str2.size();

        for (int i = n - 1; i >= 0; i--)
        {
            if (n % (i + 1) == 0 && m % (i + 1) == 0)
            {
                auto x = str1.substr(0, i + 1);
                auto s = x;
                auto t = x;
                while (s.size() < n)
                    s += x;
                while (t.size() < m)
                    t += x;
                if (s == str1 && t == str2)
                    return x;
            }
        }
        return "";
    }
};
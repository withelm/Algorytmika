class Solution
{
private:
    bool check(string &s)
    {
        int begin = 0;
        int end = s.size() - 1;

        int diffrent = 0;
        while (begin < end)
        {
            //  cout << begin << " " << s[begin] << " " << end << " " << s[end] << endl;
            if (s[begin] == s[end])
            {
                ++begin;
                --end;
                continue;
            }
            ++diffrent;
            if (s[begin + 1] == s[end])
            {
                //      cout << ">" << endl;
                ++begin;
                continue;
            }
            if (s[begin] == s[end - 1])
            {
                //   cout << ">>" << endl;
                --end;
                continue;
            }
            //  cout << ">>>" << endl;
            return false;
        }
        return diffrent <= 1;
    }

public:
    bool validPalindrome(string s)
    {
        if (check(s))
            return true;
        reverse(s.begin(), s.end());
        return check(s);
    }
};
class Solution
{

private:
    bool check(vector<int> &x, int k)
    {
        int r = 0;
        for (auto &i : x)
            r += i > 0;
        //  for(char i = 'a'; i <= 'z'; i++) if (x[i] > 0) cout << i << " " << x[i] << endl;
        return r <= k;
    }

public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        if (s.size() == 0)
            return 0;
        if (k == 0)
            return 0;

        vector<int> kub(255, 0);

        int begin = 0;
        int end = 1;
        int r = 1;
        int n = s.size();
        ++kub[s[0]];

        while (end < n)
        {
            ++kub[s[end++]];
            if (check(kub, k))
            {
                //cout << begin << " " << end << endl;
                r = max(r, end - begin);
            }
            else
            {
                --kub[s[begin++]];
            }
            if (begin == end)
            {
                ++end;
                ++kub[s[begin]];
            }
            //      cout << endl;
        }
        r = max(r, end - begin);
        return r;
    }
};
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        int index_n = 0;
        int index_m = 0;
        int r = 0;
        while (index_n < n && index_m < m)
        {
            while (index_m < m && s[index_n] != t[index_m])
            {
                ++index_m;
            }
            // cout << index_n << " " << index_m << endl;
            r += (s[index_n] == t[index_m]);
            ++index_n;
            ++index_m;
        }
        //   cout << r << endl;
        return r == n;
    }
};
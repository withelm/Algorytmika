class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        int i_n = 0;
        int i_m = 0;

        string r = "";

        for (int i = 0; i < min(n, m); i++)
        {
            r += word1[i_n++];
            r += word2[i_m++];
        }
        while (i_n < n)
            r += word1[i_n++];
        while (i_m < m)
            r += word2[i_m++];

        return r;
    }
};
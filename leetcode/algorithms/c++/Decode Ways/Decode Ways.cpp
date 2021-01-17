class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> t(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (s[i] > '0' && s[i] <= '9')
            {
                if (i == 0)
                    t[i] = 1;
                else
                    t[i] = t[i - 1];
            }
            if (i != 0)
            {
                int val = s[i - 1] - '0';
                val *= 10;
                val += s[i] - '0';
                if (val >= 10 && val <= 26)
                    if (i > 1)
                        t[i] += t[i - 2];
                    else
                        t[i]++;
            }
            cout << t[i] << endl;
        }
        return t[n - 1];
    }
};
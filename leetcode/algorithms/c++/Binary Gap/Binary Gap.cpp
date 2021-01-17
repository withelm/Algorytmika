class Solution
{
public:
    int binaryGap(int N)
    {
        if (N == 0)
            return 0;

        vector<int> b;

        while (N > 0)
        {
            b.push_back(N % 2);
            N /= 2;
        }
        reverse(b.begin(), b.end());

        int r = 0;
        vector<int> d;
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i] == 1)
                d.push_back(i);
        }
        for (int i = 1; i < d.size(); i++)
        {
            r = max(r, d[i] - d[i - 1]);
        }
        return r;
    }
};
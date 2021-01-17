class Solution
{
public:
    vector<int> numMovesStones(int a, int b, int c)
    {
        vector<int> t = {a, b, c};
        sort(t.begin(), t.end());
        a = t[0];
        b = t[1];
        c = t[2];

        int r1 = 0;
        int r11 = 0;
        int r2 = 0;
        if (b - a > 1)
        {
            r1 += b - a - 1;
            r2 += b - a - 1;
        }
        if (c - b > 1)
        {
            r11 += c - b - 1;
            r2 += c - b - 1;
        }
        if (r1 == 0 && r11 == 0)
            return {0, r2};
        if (r1 < 2 || r11 < 2)
            return {1, r2};
        return {2, r2};
    }
};
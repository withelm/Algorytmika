class Solution
{

private:
    bool calc(vector<bool> &t, int x)
    {
        int i = 1;
        while (i * i <= x)
        {
            if (!t[x - i * i])
                return true;
            ++i;
        }
        return false;
    }

public:
    bool winnerSquareGame(int n)
    {
        vector<bool> t(n + 10, false);
        for (int i = 1; i <= n; i++)
        {
            t[i] = calc(t, i);
        }
        return t[n];
    }
};
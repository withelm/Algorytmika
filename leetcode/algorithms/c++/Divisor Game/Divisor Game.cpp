class Solution
{
private:
    bool check(int n, vector<bool> &t)
    {

        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0 && (!t[n - i] || !t[n - (n / i)]))
                return true;
        }
        return false;
    }

public:
    bool divisorGame(int N)
    {
        vector<bool> t(N + 10, false);
        t[0] = true;
        t[1] = false;
        t[2] = true;

        for (int i = 3; i < N + 10; i++)
        {
            t[i] = check(i, t);
        }

        return t[N];
    }
};
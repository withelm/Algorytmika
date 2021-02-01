class Solution
{

public:
    int numTrees(int n)
    {
        // (2n)!/(n!(n+1)!)
        long long int r = 1;
        set<int> toDiv;
        for (int i = 2; i <= n; i++)
            toDiv.insert(i);

        for (int i = n + 2; i <= 2 * n; i++)
        {
            r *= i;
            vector<int> removed;
            for (auto &x : toDiv)
            {
                if (r % x == 0)
                {
                    r /= x;
                    removed.push_back(x);
                }
            }
            for (auto &x : removed)
            {
                toDiv.erase(x);
            }
        }

        return r;
    }
};
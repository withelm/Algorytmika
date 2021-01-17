class Solution
{
private:
    vector<int> generate(int k)
    {
        vector<int> r;
        for (int i = 1; i <= (10 - k); i++)
        {
            int tmp = i;
            int n = k - 1;
            while (n--)
            {
                tmp = tmp * 10 + ((tmp % 10) + 1);
            }
            r.push_back(tmp);
        }
        return r;
    }

public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> r;
        for (int i = 1; i <= 9; i++)
        {
            auto tmp = generate(i);
            for (auto &x : tmp)
            {
                if (low <= x && x <= high)
                {
                    r.push_back(x);
                }
            }
        }
        return r;
    }
};
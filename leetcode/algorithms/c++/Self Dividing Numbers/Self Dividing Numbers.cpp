class Solution
{
private:
    bool check(int x)
    {
        int last = x;
        while (x > 0)
        {
            int tmp = x % 10;

            if (tmp != 0)
            {
                if (last % tmp != 0)
                    return false;
            }
            else
            {
                return false;
            }
            x /= 10;
        }
        return true;
    }

public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> result;
        for (int i = left; i <= right; i++)
        {
            if (check(i))
                result.push_back(i);
        }
        return result;
    }
};
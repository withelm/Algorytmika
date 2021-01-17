class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        set<int> r;
        int i = 0, j = 0;

        while (pow(x, i) + pow(y, j) <= bound)
        {
            while (pow(x, i) + pow(y, j) <= bound)
            {
                r.insert(pow(x, i) + pow(y, j));
                ++j;
                if (y == 1)
                    break;
            }
            j = 0;
            ++i;
            if (x == 1)
                break;
        }

        vector<int> result;
        for (auto &x : r)
            result.push_back(x);
        return result;
    }
};
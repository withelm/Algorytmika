class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        vector<int> kub(100, 0);

        for (auto &x : bills)
        {

            if (x == 5)
            {
                ++kub[5];
                continue;
            }
            if (x == 10)
            {
                if (kub[5] == 0)
                    return false;
                ++kub[10];
                --kub[5];
                continue;
            }
            if (kub[10] >= 1 && kub[5] >= 1)
            {
                ++kub[20];
                --kub[10];
                --kub[5];
                continue;
            }
            if (kub[5] >= 3)
            {
                ++kub[20];
                kub[5] -= 3;
                continue;
            }

            return false;
        }
        return true;
    }
};
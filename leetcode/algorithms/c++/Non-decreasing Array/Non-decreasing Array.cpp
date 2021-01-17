class Solution
{
private:
    bool checkArray(vector<int> &t, int n, int block)
    {
        for (int i = 1; i < n; i++)
        {
            if (i == block)
                continue;

            if (i - 1 == block)
            {

                if (i - 2 >= 0 && t[i - 2] > t[i])
                    return false;
                continue;
            }
            if (t[i - 1] > t[i])
                return false;
        }
        return true;
    }

public:
    bool checkPossibility(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = -1; i < n; i++)
        {

            if (checkArray(nums, n, i))
                return true;
        }
        return false;
    }
};
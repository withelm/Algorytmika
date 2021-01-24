class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        vector<int> up, down;
        for (auto &x : nums)
            if (x >= 0)
                up.push_back(x);
            else
                down.push_back(x);

        if (nums.size() == 3)
            return nums[0] * nums[1] * nums[2];

        sort(up.begin(), up.end());
        sort(down.begin(), down.end());

        if (down.size() == 0)
        {
            return up[up.size() - 1] * up[up.size() - 2] * up[up.size() - 3];
        }
        else if (down.size() == 1 && up.size() > 2)
        {
            return up[up.size() - 1] * up[up.size() - 2] * up[up.size() - 3];
        }
        else if (up.size() == 0)
        {
            return down[down.size() - 1] * down[down.size() - 2] * down[down.size() - 3];
        }
        else if (up.size() < 3)
        {
            return down[0] * down[1] * up[up.size() - 1];
        }
        else
            return max(down[0] * down[1] * up[up.size() - 1], up[up.size() - 1] * up[up.size() - 2] * up[up.size() - 3]);
    }
};
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        auto it = unique(nums.begin(), nums.end());

        nums.resize(distance(nums.begin(), it));
        if (nums.size() == 0)
            return 0;

        int r = 1;
        bool way = false;
        int tmp = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] + 1 == nums[i])
            {
                if (way)
                {
                    ++tmp;
                }
                else
                {
                    way = true;
                    tmp = 2;
                }
            }
            else
            {
                if (way)
                {
                    tmp = 0;
                    way = false;
                }
            }
            r = max(r, tmp);
        }

        return r;
    }
};
class Solution
{
public:
    int colors[4];
    void sortColors(vector<int> &nums)
    {
        colors[0] = colors[1] = colors[2] = 0;
        for (auto &num : nums)
        {
            ++colors[num];
        }
        int index = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < colors[i]; j++)
            {
                nums[index++] = i;
            }
        }
    }
};
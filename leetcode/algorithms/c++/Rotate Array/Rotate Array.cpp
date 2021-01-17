class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        while (k--)
        {
            auto last = nums.back();
            nums.erase(nums.begin() + n - 1);
            nums.insert(nums.begin(), last);
        }
    }
};
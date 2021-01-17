class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        vector<int> zero;
        if (nums[0] == 0)
            zero.push_back(0);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == 1)
            {
                nums[i] += nums[i - 1];
            }
            else
            {
                zero.push_back(i);
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] != 0 && nums[i + 1] != 0)
            {
                nums[i] = nums[i + 1];
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++)
            result = max(result, nums[i]);
        for (auto &x : zero)
        {
            //    cout << x - 1 << " " << x << " " << x + 1 << endl;
            //    cout << nums[x - 1] << " " << nums[x] << " " << nums[x + 1] << endl;
            if (x - 1 >= 0 && x + 1 >= n)
                result = max(result, nums[x - 1] + 1);
            if (x - 1 < 0 && x + 1 < n)
                result = max(result, nums[x + 1] + 1);
            if (x - 1 >= 0 && x + 1 < n)
                result = max(result, nums[x - 1] + nums[x + 1] + 1);
        }
        return result;
    }
};
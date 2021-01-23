class Solution
{
public:
    vector<int> largestSubarray(vector<int> &nums, int k)
    {
        map<int, int> base;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            base[nums[i]] = i;

        vector<int> t = nums;
        sort(t.begin(), t.end());
        for (int i = n - 1; i >= 0; i--)
        {
            if (n - base[t[i]] >= k)
            {
                vector<int> tmp;
                int index = base[t[i]];
                for (int j = 0; j < k; j++)
                {
                    tmp.push_back(nums[index + j]);
                }
                return tmp;
            }
        }
        return {};
    }
};
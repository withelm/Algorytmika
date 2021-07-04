class Solution
{
private:
    int n;
    vector<int> nums;

    bool check(int k, int limit)
    {
        vector<int> t = {0, 0};
        for (int i = 0; i < min(k, n); i++)
        {
            ++t[nums[i]];
        }
        for (int i = k; i < n; i++)
        {
            if (t[0] <= limit)
                return true;
            --t[nums[i - k]];
            ++t[nums[i]];
        }
        return t[0] <= limit;
    }

public:
    int longestOnes(vector<int> &_nums, int k)
    {
        nums = _nums;
        n = nums.size();

        int right = n;
        int left = 0;

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (left == mid || right == mid)
                break;
            if (check(mid, k))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        vector<int> toCheck = {left, left - 1, left + 1, right, right + 1, right - 1};
        sort(toCheck.begin(), toCheck.end());
        for (int i = toCheck.size() - 1; i >= 0; i--)
        {
            if (check(toCheck[i], k))
                return min(toCheck[i], n);
        }
        return -1;
    }
};
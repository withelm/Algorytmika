class Solution
{
private:
    bool check(vector<int> &x, int k, int t)
    {
        if (k == 0)
            return false;
        int sum = 0;
        for (auto &i : x)
        {
            sum += i / k + (i % k != 0);
        }
        // cout << "> " << k << " " << sum << endl;
        return sum <= t;
    }

public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int mid = (left + right) / 2;
        while (left < right)
        {
            //   cout << left << " " << right << endl;
            mid = (left + right) / 2;
            if (check(nums, mid, threshold))
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        for (int i = min(mid, min(left, right)); i < max(mid, max(left, right)) + 10; i++)
            if (check(nums, i, threshold))
                return i;

        return left;
    }
};
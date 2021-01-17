class Solution
{

private:
    bool check_begin(int index, vector<int> &nums)
    {
        for (int i = index + 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[index])
                return false;
        }
        return true;
    }

    bool check_end(int index, vector<int> &nums)
    {
        for (int i = index - 1; i >= 0; i--)
        {
            if (nums[i] > nums[index])
                return false;
        }
        return true;
    }

public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int begin = 0;
        int end = nums.size() - 1;
        int n = nums.size();

        while (begin < n && check_begin(begin, nums))
        {
            ++begin;
        }

        while (end >= 0 && check_end(end, nums))
        {
            --end;
        }

        return max(0, end - begin + 1);
    }
};
class Solution
{
private:
    set<int> k;

public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int begin = 0;
        int end = numbers.size() - 1;
        while (begin < end)
        {

            if (numbers[begin] + numbers[end] == target)
                break;
            if (numbers[begin] + numbers[end] > target)
                --end;
            else
                ++begin;
        }
        return {begin + 1, end + 1};
    }
};
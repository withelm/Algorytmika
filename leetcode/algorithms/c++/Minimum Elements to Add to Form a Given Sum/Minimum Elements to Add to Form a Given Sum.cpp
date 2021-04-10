class Solution
{
public:
    int minElements(vector<int> &nums, int limit, int goal)
    {
        long long int sum = 0;
        for (auto &x : nums)
            sum += x;

        long long int dist = abs(goal - sum);
        return dist / limit + (dist % limit != 0);
    }
};

struct CustomCompare
{
    bool operator()(const vector<int> &lhs, const vector<int> &rhs)
    {
        return lhs[0] < rhs[0];
    }
};

class Solution
{
private:
    priority_queue<vector<int>, vector<vector<int>>, CustomCompare> q;

public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        q.push({nums[0], 0});
        for (int i = 1; i < n; i++)
        {

            while (q.top()[1] < i - k)
            {
                q.pop();
            }
            nums[i] += q.top()[0];
            q.push({nums[i], i});
        }
        return nums[n - 1];
    }
};
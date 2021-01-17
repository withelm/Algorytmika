class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int n = nums.size();
        int m = nums[0].size();
        if (n * m != r * c)
            return nums;

        vector<vector<int>> res(r, vector<int>(c, 0));

        int r_i = 0;
        int c_i = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                res[r_i][c_i] = nums[i][j];
                ++c_i;
                if (c_i >= c)
                {
                    ++r_i;
                    c_i = 0;
                }
            }
        }
        return res;
    }
};
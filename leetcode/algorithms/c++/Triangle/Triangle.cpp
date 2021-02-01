class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        for (int i = 1; i < triangle.size(); i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                int minimum = 1e9;
                if (j < triangle[i - 1].size())
                    minimum = min(minimum, triangle[i - 1][j]);
                if (j - 1 >= 0)
                    minimum = min(minimum, triangle[i - 1][j - 1]);
                triangle[i][j] += minimum;
            }
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};
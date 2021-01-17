class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (auto &row : matrix)
        {
            for (auto &column : row)
            {
                if (column == target)
                    return true;
            }
        }
        return false;
    }
};
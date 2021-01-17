class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (auto &x : matrix)
        {
            if (binary_search(x.begin(), x.end(), target))
                return true;
        }
        return false;
    }
};
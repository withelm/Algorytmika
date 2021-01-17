class Solution
{
private:
    int shift(vector<vector<int>> &A, vector<vector<int>> &B, int x, int y)
    {
        int row = 0;
        int column = 0;
        int result = 0;
        int n = A.size();
        for (int i = x; i < n; i++)
        {
            column = 0;
            for (int j = y; j < n; j++)
            {
                if (A[i][j] == B[row][column] && A[i][j] == 1)
                    ++result;
                ++column;
            }
            ++row;
        }
        return result;
    }

public:
    int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int n = A.size();
        int result = 0;
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {
                result = max(result, shift(A, B, i, j));
                result = max(result, shift(B, A, i, j));
            }
        }
        return result;
    }
};
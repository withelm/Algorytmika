class Solution
{
private:
    void updateData(vector<vector<int>> &result, vector<int> indice)
    {
        int n = result.size();
        int m = result[0].size();

        for (int i = 0; i < n; i++)
        {
            ++result[i][indice[1]];
        }
        for (int i = 0; i < m; i++)
        {
            ++result[indice[0]][i];
        }
    }

public:
    int oddCells(int n, int m, vector<vector<int>> &indices)
    {
        vector<vector<int>> result(n);
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp(m);
            result[i] = tmp;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                result[i][j] = 0;
            }
        }
        for (auto &indice : indices)
        {
            updateData(result, indice);
        }

        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                answer += result[i][j] % 2;
            }
        }
        return answer;
    }
};
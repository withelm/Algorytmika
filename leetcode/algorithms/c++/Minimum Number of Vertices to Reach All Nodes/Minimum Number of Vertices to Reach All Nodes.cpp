class Solution
{
private:
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<int> counter(n);
        for (auto &x : edges)
        {
            ++counter[x[1]];
        }
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (counter[i] == 0)
                result.push_back(i);
        }
        return result;
    }
};
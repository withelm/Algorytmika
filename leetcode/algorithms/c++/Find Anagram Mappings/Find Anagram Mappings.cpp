class Solution
{
private:
    int find(int x, map<int, vector<int>> &base)
    {
        int result = base[x].back();
        base[x].pop_back();
        return result;
    }

public:
    vector<int> anagramMappings(vector<int> &A, vector<int> &B)
    {
        map<int, vector<int>> base;
        int index = 0;
        for (auto &x : B)
        {
            base[x].push_back(index++);
        }
        vector<int> result(A.size());
        for (int i = 0; i < A.size(); i++)
        {
            result[i] = find(A[i], base);
        }
        return result;
    }
};
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        vector<int> result;
        for (auto &it : A)
        {
            if (it % 2 == 0)
            {
                result.push_back(it);
            }
        }
        for (auto &it : A)
        {
            if (it % 2 == 1)
            {
                result.push_back(it);
            }
        }
        return result;
    }
};
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> copy;
        for (vector<int>::iterator it = heights.begin(); it != heights.end(); it++)
        {
            copy.push_back(*it);
        }
        sort(copy.begin(), copy.end());

        int result = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            result += heights[i] != copy[i];
        }
        return result;
    }
};
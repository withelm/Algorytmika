class Solution
{
public:
    bool isMonotonic(vector<int> &A)
    {
        vector<int> t = A;
        int n = A.size();

        int up = 0;
        int down = 0;

        for (int i = 1; i < n; i++)
        {
            if (t[i] - t[i - 1] > 0)
                ++up;
            if (t[i] - t[i - 1] < 0)
                ++down;
        }

        return up == 0 || down == 0;
    }
};
class Solution
{

private:
    int calc(vector<int> &height)
    {
        int r = 0;

        int begin_val = height[0];

        int n = height.size();
        int limit_index = 0;
        for (int i = 1; i < n; i++)
        {
            if (height[i] >= height[limit_index])
            {
                limit_index = i;
            }
        }
        height[limit_index] = 1e9;
        for (int i = 1; i <= limit_index; i++)
        {

            if (height[i] <= begin_val)
            {
                r += begin_val - height[i];
            }
            else
            {
                begin_val = height[i];
            }
            // cout << i << " " << height[i] << " " << begin_val << " " << r << endl;
        }
        return r;
    }

public:
    int trap(vector<int> &height)
    {

        if (height.size() == 0)
            return 0;

        int r = calc(height);
        reverse(height.begin(), height.end());
        return r + calc(height);
    }
};
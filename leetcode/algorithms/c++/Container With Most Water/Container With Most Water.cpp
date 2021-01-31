class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int r = 0;
        int n = height.size();
        int begin = 0;
        int end = n - 1;
        while (begin < end)
        {
            r = max(r, (end - begin) * min(height[begin], height[end]));
            if (height[begin] < height[end])
                ++begin;
            else
                --end;
        }

        return r;
    }
};
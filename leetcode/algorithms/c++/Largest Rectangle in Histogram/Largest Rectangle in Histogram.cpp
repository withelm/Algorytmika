class Solution
{
private:
    vector<int> h;
    int ans = 0;

    void dfs(int left, int right)
    {

        if (left >= right)
            return;
        // cout << left << " " << right << endl;
        int minimum = h[left];
        int minimum_index = left;

        for (int i = left; i < right; i++)
        {
            if (minimum > h[i])
            {
                minimum = h[i];
                minimum_index = i;
            }
        }

        ans = max(ans, (right - left) * minimum);
        dfs(left, minimum_index);
        dfs(minimum_index + 1, right);
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        h = heights;

        dfs(0, h.size());

        return ans;
    }
};
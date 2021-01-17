class Solution
{
private:
    int MX = 1 << 17;
    int MX2 = MX * 2;
    int INF = -1e6;
    vector<int> tree;

    void insert(int val, int index)
    {
        index += MX;
        tree[index] = val;
        index /= 2;
        while (index != 0)
        {
            tree[index] = max(tree[index * 2], tree[index * 2 + 1]);
            index /= 2;
        }
    }

    void init(int n)
    {
        int lg = log2(n) + 1;
        MX = 1 << lg;
        MX2 = MX * 2;
        tree.resize(MX2);
        for (int i = 0; i < MX; i++)
        {
            insert(INF, i);
        }
    }

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        init(n);

        vector<int> r;
        for (int i = 0; i < k; i++)
        {
            insert(nums[i], i);
        }
        r.push_back(tree[1]);
        for (int i = k; i < n; i++)
        {
            insert(INF, i - k);
            insert(nums[i], i);
            r.push_back(tree[1]);
        }

        return r;
    }
};
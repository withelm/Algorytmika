class Solution
{
private:
    vector<int> t, m, t2;
    int f(int x, vector<int> &t)
    {
        if (x == 0)
            return m[0];
        if (x == 1)
            return max(m[0], m[1]);
        return max(t[x - 2] + m[x], t[x - 1]);
    }
    int f2(int x, vector<int> &t)
    {
        if (x == 1)
            return m[1];
        if (x == 2)
            return max(m[1], m[2]);
        return max(t[x - 2] + m[x], t[x - 1]);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        m = nums;
        t.resize(n + 10);
        t2.resize(n + 10);
        for (int i = 0; i < n - 1; i++)
        {
            t[i] = f(i, t);
            //    cout << i << " " << t[i] << endl;
        }
        //  cout << endl;
        for (int i = 1; i < n; i++)
        {
            t2[i] = f2(i, t2);
            // cout << i << " " << t2[i] << endl;
        }
        return max(*max_element(t.begin(), t.end()), *max_element(t2.begin(), t2.end()));
    }
};
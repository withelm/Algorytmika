class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> r(n, 0);

        for (int i = 0; i < n; i++)
        {
            int val = 0;
            int tmp_k = k;
            while (tmp_k > 0)
            {
                val += code[(i + tmp_k) % n];
                --tmp_k;
            }
            while (tmp_k < 0)
            {
                val += code[(i + tmp_k + n) % n];
                ++tmp_k;
            }
            r[i] = val;
        }
        return r;
    }
};
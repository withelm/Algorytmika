class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &A, int K)
    {
        vector<int> up;
        vector<int> down;
        for (auto &x : A)
        {
            if (x >= 0)
                up.push_back(x);
            else
                down.push_back(x);
        }

        sort(up.begin(), up.end());
        sort(down.begin(), down.end());

        if (down.size() == 0)
        {
            if (K % 2 == 1)
                up[0] *= -1;
        }
        else
        {
            if (K <= down.size())
            {
                for (int i = 0; i < K; i++)
                    down[i] *= -1;
            }
            else
            {
                for (int i = 0; i < down.size(); i++)
                    up.push_back(-down[i]);
                K -= down.size();
                down.clear();
                sort(up.begin(), up.end());

                if (K % 2 == 1)
                    up[0] *= -1;
            }
        }

        int res = 0;
        for (auto &x : up)
            res += x;
        for (auto &x : down)
            res += x;
        return res;
    }
};
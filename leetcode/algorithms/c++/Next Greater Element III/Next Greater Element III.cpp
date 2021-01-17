class Solution
{
public:
    int nextGreaterElement(int n)
    {
        int m = n;
        vector<int> t;
        while (m > 0)
        {
            t.push_back(m % 10);
            m /= 10;
        }
        sort(t.begin(), t.end());
        vector<int> r;
        do
        {
            long long int tmp = 0;
            for (auto &x : t)
            {
                tmp = tmp * 10 + x;
            }
            r.push_back(tmp);
        } while (next_permutation(t.begin(), t.end()));

        sort(r.begin(), r.end());
        //  for(auto &x : r) cout << x << endl;
        for (auto &x : r)
        {
            if (x > n)
                return x;
        }
        return -1;
    }
};
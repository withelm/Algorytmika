class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        vector<int> a;
        vector<int> b;
        vector<int> r;
        for (auto &x : A)
        {
            if (x % 2 == 0)
                a.push_back(x);
            else
                b.push_back(x);
        }
        for (int i = 0; i < a.size(); i++)
        {
            r.push_back(a[i]);
            r.push_back(b[i]);
        }
        return r;
    }
};
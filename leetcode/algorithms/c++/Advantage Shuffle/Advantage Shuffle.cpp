class Solution
{
public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B)
    {
        vector<int> r;
        sort(A.begin(), A.end());
        for (auto &x : B)
        {
            vector<int>::iterator find;
            if (A.back() > x)
            {
                find = upper_bound(A.begin(), A.end(), x);
            }
            else
            {
                find = A.begin();
            }
            r.push_back(*find);
            A.erase(find);
        }
        return r;
    }
};
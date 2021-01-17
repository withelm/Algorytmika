class Solution
{
public:
    int countElements(vector<int> &arr)
    {
        set<int> t;
        for (auto &x : arr)
            t.insert(x);

        int r = 0;

        for (auto &x : arr)
        {
            r += t.find(x + 1) != t.end();
        }
        return r;
    }
};
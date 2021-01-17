class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        int index = 1;
        vector<string> r;
        for (auto &x : target)
        {
            while (index < x)
            {
                r.push_back("Push");
                r.push_back("Pop");
                ++index;
            }
            r.push_back("Push");
            ++index;
        }
        return r;
    }
};
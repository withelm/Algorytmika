class Solution
{
private:
    map<int, int> base;

public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> r;

        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < m; i++)
            base[nums2[i]] = i;

        for (int i = 0; i < n; i++)
        {
            bool check = false;
            for (int j = base[nums1[i]] + 1; j < m; j++)
            {
                if (nums1[i] < nums2[j])
                {
                    r.push_back(nums2[j]);
                    check = true;
                    break;
                }
            }
            if (!check)
                r.push_back(-1);
        }
        return r;
    }
};
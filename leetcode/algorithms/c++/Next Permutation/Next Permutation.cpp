class Solution
{
public:
    void nextPermutation(vector<int> &s)
    {
        if (!next_permutation(s.begin(), s.end()))
            sort(s.begin(), s.end());
    }
};
class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        vector<int> one;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '1')
                one.push_back(i);
        if (one.size() == 0)
            return false;
        for (int i = 0; i < one.size() - 1; i++)
        {
            if (one[i + 1] - one[i] != 1)
                return false;
        }
        return true;
    }
};
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        string result = "";
        if (strs.size() == 0)
            return result;
        int min_len = strs[0].size();
        for (int i = 1; i < strs.size(); i++)
        {
            if (min_len > strs[i].size())
                min_len = strs[i].size();
        }

        int index = 0;
        while (index < min_len)
        {
            char acc = strs[0][index];
            bool isAll = true;
            for (int i = 1; i < strs.size(); i++)
            {
                if (acc != strs[i][index])
                {
                    isAll = false;
                    break;
                }
            }
            if (isAll)
            {
                result += acc;
            }
            else
            {
                break;
            }
            ++index;
        }
        return result;
    }
};
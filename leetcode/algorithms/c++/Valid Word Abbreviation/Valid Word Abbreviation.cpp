class Solution
{
public:
    bool validWordAbbreviation(string word, string abbr)
    {
        string fullAbbr = "";
        for (int i = 0; i < abbr.size();)
        {
            if (abbr[i] >= '1' && abbr[i] <= '9')
            {
                int tmp = abbr[i] - '0';
                ++i;
                while (abbr[i] >= '0' && abbr[i] <= '9')
                {
                    tmp = tmp * 10 + (abbr[i] - '0');
                    ++i;
                }
                if (tmp > word.size())
                    return false;
                while (tmp--)
                {
                    fullAbbr.push_back('*');
                }
            }
            else
            {
                fullAbbr.push_back(abbr[i]);
                ++i;
            }
        }
        // if (word.size() < abbr.size())
        //     return false;
        if (word.size() != fullAbbr.size())
            return false;
        for (int i = 0; i < word.size(); i++)
        {
            if (fullAbbr[i] != '*' && word[i] != fullAbbr[i])
                return false;
        }
        return true;
    }
};
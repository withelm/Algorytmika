class Solution
{
public:
    bool isStrobogrammatic(string num)
    {
        vector<char> block = {'2', '3', '4', '5', '7'};
        for (auto &i : num)
        {
            for (auto &j : block)
            {
                if (i == j)
                    return false;
            }
        }
        map<char, char> base;
        base['0'] = '0';
        base['1'] = '1';
        base['6'] = '9';
        base['8'] = '8';
        base['9'] = '6';

        string newStr = "";
        for (auto &x : num)
        {
            newStr += base[x];
        }
        reverse(newStr.begin(), newStr.end());

        return num == newStr;
    }
};
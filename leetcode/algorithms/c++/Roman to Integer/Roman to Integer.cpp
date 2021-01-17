class Solution
{
private:
    map<string, int> data;
    vector<string> special = {"IV", "IX", "XL", "XC", "CD", "CM"};

public:
    int romanToInt(string s)
    {
        data["I"] = 1;
        data["V"] = 5;
        data["X"] = 10;
        data["L"] = 50;
        data["C"] = 100;
        data["D"] = 500;
        data["M"] = 1000;
        data["IV"] = 4;
        data["IX"] = 9;
        data["XL"] = 40;
        data["XC"] = 90;
        data["CD"] = 400;
        data["CM"] = 900;
        int result = 0;
        for (int i = 0; i < s.size();)
        {
            if (i + 1 < s.size())
            {
                string tmpStr;
                tmpStr += s[i];
                tmpStr += s[i + 1];

                int tmp = data[tmpStr];
                if (tmp != 0)
                {
                    result += tmp;
                    i += 2;
                    continue;
                }
            }
            string tmpStr;
            tmpStr += s[i];
            result += data[tmpStr];
            ++i;
        }
        return result;
    }
};
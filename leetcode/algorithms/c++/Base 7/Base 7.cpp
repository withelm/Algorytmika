class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
            return "0";
        bool isLess = false;
        if (num < 0)
        {
            isLess = true;
            num *= -1;
        }
        string r = "";
        while (num > 0)
        {
            r += (num % 7) + '0';
            num /= 7;
        }
        if (isLess)
            r += "-";
        reverse(r.begin(), r.end());
        return r;
    }
};
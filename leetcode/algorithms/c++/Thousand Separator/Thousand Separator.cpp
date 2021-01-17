class Solution
{
private:
public:
    string thousandSeparator(int n)
    {
        if (n == 0)
            return "0";
        string result = "";
        int k = 1;
        while (n > 0)
        {
            result += (n % 10) + '0';
            n /= 10;
            if (k % 3 == 0 && n != 0)
                result += ".";

            ++k;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
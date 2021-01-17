class Solution
{
public:
    string convertToTitle(int n)
    {
        string result = "";
        --n;
        while (n >= 0)
        {
            result += (n % 26) + 'A';
            n /= 26;
            --n;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
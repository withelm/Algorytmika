class Solution
{
public:
    string generateTheString(int n)
    {
        string result = "";
        if (n % 2 == 0)
        {
            if ((n / 2) % 2 == 1)
            {
                for (int i = 0; i < n / 2; i++)
                {
                    result += "a";
                }
                for (int i = 0; i < n / 2; i++)
                {
                    result += "b";
                }
            }
            else
            {
                for (int i = 0; i < n / 2 + 1; i++)
                {
                    result += "a";
                }
                for (int i = 0; i < n / 2 - 1; i++)
                {
                    result += "b";
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                result += "a";
            }
        }
        return result;
    }
};
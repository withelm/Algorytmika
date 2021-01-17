class Solution
{
private:
    string update(string x)
    {
        string result = "";
        int index = 1;
        char c = x[0];
        for (int i = 1; i < x.size(); i++)
        {
            if (c == x[i])
            {
                ++index;
            }
            else
            {
                result += index + '0';
                result += c;
                c = x[i];
                index = 1;
            }
        }
        result += index + '0';
        result += c;
        return result;
    }

public:
    string countAndSay(int n)
    {
        string result = "1";
        --n;
        while (n--)
        {
            result = update(result);
        }
        return result;
    }
};
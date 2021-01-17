class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        if (num1.size() > num2.size())
            swap(num1, num2);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int n = num1.size();
        int m = num2.size();

        string num3 = "";
        int tmp = 0;

        for (int i = 0; i < n; i++)
        {
            tmp = tmp + (num1[i] - '0') + (num2[i] - '0');
            num3 += (tmp % 10) + '0';
            tmp /= 10;
        }
        for (int i = n; i < m; i++)
        {
            tmp = tmp + (num2[i] - '0');
            num3 += (tmp % 10) + '0';
            tmp /= 10;
        }
        if (tmp != 0)
        {
            num3 += tmp + '0';
        }
        reverse(num3.begin(), num3.end());
        return num3;
    }
};
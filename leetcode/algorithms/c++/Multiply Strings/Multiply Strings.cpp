class Solution
{
private:
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

public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string result = "0";
        int index = 0;
        for (auto &dig : num1)
        {
            string tmp = "";
            int dg = dig - '0';
            int val = 0;

            for (auto &x : num2)
            {
                int dg2 = x - '0';
                val += dg * dg2;
                tmp += (val % 10) + '0';
                val /= 10;
            }
            while (val > 0)
            {
                tmp += (val % 10) + '0';
                val /= 10;
            }
            reverse(tmp.begin(), tmp.end());
            for (int i = 0; i < index; i++)
                tmp += "0";
            result = addStrings(result, tmp);
            ++index;
        }

        return result;
    }
};
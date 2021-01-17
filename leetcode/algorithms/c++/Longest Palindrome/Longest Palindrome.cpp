class Solution
{
public:
    int datas[255 + 10];
    int longestPalindrome(string s)
    {
        int result = 0;
        for (int i = 0; i < 255 + 10; i++)
        {
            datas[i] = 0;
        }
        for (int i = 0; i < s.size(); i++)
        {

            ++datas[s[i]];
        }

        bool isEven = false;
        for (int i = 0; i < 255 + 10; i++)
        {

            if (datas[i] % 2 == 1)
                isEven = true;
            result += (datas[i] / 2) * 2;
        }
        return result + isEven;
    }
};
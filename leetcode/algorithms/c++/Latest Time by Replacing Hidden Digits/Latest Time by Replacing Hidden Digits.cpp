class Solution
{
private:
    bool isValid(string &x)
    {
        int hour = x[0] - '0';
        hour = 10 * hour + x[1] - '0';
        int min = x[3] - '0';
        min = 10 * min + x[4] - '0';
        return hour >= 0 && hour <= 23 && min >= 0 && min <= 59;
    }

public:
    string maximumTime(string time)
    {
        for (int i = 9; i >= 0; i--)
        {
            for (int j = 9; j >= 0; j--)
            {
                for (int k = 9; k >= 0; k--)
                {
                    for (int l = 9; l >= 0; l--)
                    {
                        string tmp = time;
                        if (tmp[0] == '?')
                            tmp[0] = i + '0';
                        if (tmp[1] == '?')
                            tmp[1] = j + '0';
                        if (tmp[3] == '?')
                            tmp[3] = k + '0';
                        if (tmp[4] == '?')
                            tmp[4] = l + '0';

                        if (isValid(tmp))
                            return tmp;
                    }
                }
            }
        }
        return "";
    }
};
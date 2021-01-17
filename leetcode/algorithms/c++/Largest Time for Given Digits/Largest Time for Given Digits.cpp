class Solution
{
private:
    bool isCorrect(int h, int m)
    {
        return h >= 0 && h < 24 && m >= 0 && m < 60;
    }

public:
    string largestTimeFromDigits(vector<int> &A)
    {
        int result = -1;
        int n = A.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    for (int l = 0; l < n; l++)
                    {
                        if (i != j && i != k && i != l && j != k && j != l && k != l)
                        {
                            if (isCorrect(A[i] * 10 + A[j], A[k] * 10 + A[l]))
                            {
                                int tmp = (A[i] * 10 + A[j]) * 60 + A[k] * 10 + A[l];
                                result = max(tmp, result);
                            }
                        }
                    }
                }
            }
        }
        if (result == -1)
            return "";
        int h = result / 60;
        int m = result % 60;
        string r = "";
        if (h < 10 && m < 10)
        {
            r += "0";
            r += h + '0';
            r += ":0";
            r += m + '0';
        }
        if (h >= 10 && m < 10)
        {
            r += (h / 10) + '0';
            r += (h % 10) + '0';
            r += ":0";
            r += m + '0';
        }
        if (h >= 10 && m >= 10)
        {
            r += (h / 10) + '0';
            r += (h % 10) + '0';
            r += ":";
            r += (m / 10) + '0';
            r += (m % 10) + '0';
        }
        if (h < 10 && m >= 10)
        {
            r += "0";
            r += h + '0';
            r += ":";
            r += (m / 10) + '0';
            r += (m % 10) + '0';
        }
        return r;
    }
};
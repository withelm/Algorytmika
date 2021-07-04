class Solution
{
private:
    int convert(string &x)
    {

        int res = 0;
        for (auto &val : x)
        {
            res = res * 2 + (val - '0');
        }
        return res;
    }

    vector<int> gray(int n)
    {
        vector<string> res = {"0", "1"};
        int i, j;
        for (int i = 2; i < (1 << n); i = i << 1)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                res.push_back(res[j]);
            }
            for (int j = 0; j < i; j++)
            {
                res[j] = "0" + res[j];
            }
            for (int j = i; j < 2 * i; j++)
            {
                res[j] = "1" + res[j];
            }
        }
        vector<int> result;
        for (auto &item : res)
            result.push_back(convert(item));
        return result;
    }

public:
    vector<int> grayCode(int n)
    {
        return gray(n);
    }
};
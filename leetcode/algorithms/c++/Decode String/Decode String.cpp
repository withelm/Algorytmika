class Solution
{
private:
    string dfs(string x, int i, int end)
    {
        //cout << x << " " << i << " " << end << endl;
        string result = "";
        bool isNumber = false;
        int num = 0;
        while (i < end)
        {
            if (!isNumber)
            {
                if (x[i] >= '0' && x[i] <= '9')
                {
                    num = x[i] - '0';
                    isNumber = true;
                    ++i;
                    continue;
                }
                else
                {
                    result += x[i];
                    ++i;
                    continue;
                }
            }
            else
            {
                if (x[i] >= '0' && x[i] <= '9')
                {
                    num *= 10;
                    num += x[i] - '0';
                    ++i;
                    continue;
                }
                else if (x[i] == '[')
                {
                    int stac = 1;
                    ++i;
                    int b_i = i;
                    while (i < end && stac != 0)
                    {
                        if (x[i] == '[')
                            ++stac;
                        if (x[i] == ']')
                            --stac;
                        ++i;
                    }
                    int e_i = i - 1;
                    auto r = dfs(x, b_i, e_i);
                    while (num--)
                        result += r;
                    isNumber = false;
                }
            }
        }
        return result;
    }

public:
    string decodeString(string s)
    {
        return dfs(s, 0, s.size());
    }
};
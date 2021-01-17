class Solution
{
private:
    int calc(int n)
    {
        if (n == 1)
            return 0;
        int result = 0;
        while (n > 0)
        {
            ++result;
            n /= 10;
        }
        return result;
    }
    void addData(vector<char> &x, int len)
    {
        vector<char> r;
        while (len > 0)
        {
            r.push_back((len % 10) + '0');
            len /= 10;
        }
        reverse(r.begin(), r.end());
        for (auto &i : r)
        {
            x.push_back(i);
        }
    }

public:
    int compress(vector<char> &chars)
    {
        vector<char> r;

        int lastChar = chars[0];
        int len = 0;
        int n = chars.size();

        int result = 0;

        for (int i = 0; i < n; i++)
        {
            if (lastChar == chars[i])
            {
                ++len;
            }
            else
            {
                r.push_back(lastChar);
                if (calc(len) != 0)
                    addData(r, len);
                result += calc(len) + 1;

                lastChar = chars[i];
                len = 1;
            }
        }
        r.push_back(lastChar);
        if (calc(len) != 0)
            addData(r, len);
        result += calc(len) + 1;
        chars = r;
        return result;
    }
};
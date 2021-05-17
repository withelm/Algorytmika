class Solution
{
private:
    int n;

    vector<string> createPair(string num, int k, int n)
    {
        string pref = "";
        string suff = "";

        for (int i = 0; i < k; i++)
        {
            pref += num[i];
        }
        for (int i = k; i < n - 1; i++)
        {
            suff += num[i];
        }
        return {pref, suff};
    }

    vector<string> generateDot(string num)
    {
        int m = num.size();

        vector<string> result;

        result.push_back(num);
        for (int i = 0; i <= m; i++)
        {
            auto r = createPair(num, i, num.size() + 1);
            if (r[0].size() > 0 && r[1].size() > 0)
            {

                result.push_back(r[0] + "." + r[1]);
            }
        }

        return result;
    }

    bool isHaveDot(string num)
    {
        for (auto &x : num)
            if (x == '.')
                return true;
        return false;
    }

    string removeLendingZero(string num)
    {
        int m = num.size();
        int index = 0;
        while (index < m && num[index] == '0')
        {
            num[index] = 0;
            ++index;
        }
        bool isHave = isHaveDot(num);
        if (isHave)
        {
            index = m - 1;
            while (index >= 0 && num[index] == '0')
            {
                num[index] = 0;
                --index;
            }
        }
        string res = "";
        for (auto &x : num)
        {
            if (x != 0)
                res += x;
        }

        if (res.size() == 0 && !isHave)
            return "0";
        if (res.size() > 0 && res[0] == '.')
            return "0" + res;
        return res;
    }

public:
    vector<string> ambiguousCoordinates(string s)
    {
        n = s.size();

        string num = "";
        for (int i = 1; i < n - 1; i++)
            num += s[i];
        vector<string> tmp;
        for (int i = 1; i < n - 2; i++)
        {
            auto r = createPair(num, i, num.size() + 1);

            auto r1 = generateDot(r[0]);
            auto r2 = generateDot(r[1]);

            for (auto &x : r1)
            {
                for (auto &y : r2)
                {

                    if (x == removeLendingZero(x) && y == removeLendingZero(y))
                    {
                        tmp.push_back("(" + x + ", " + y + ")");
                    }
                }
            }
        }

        return tmp;
    }
};
class Solution
{
private:
    bool isDigs(string s)
    {
        int dotCnt = 0;
        if (s.size() == 0)
            return false;
        if (s[0] == '-' || s[0] == '+')
            s.erase(s.begin());
        for (auto &x : s)
        {
            if (!(x >= '0' && x <= '9'))
            {
                if (x == '.')
                    ++dotCnt;
                if (x != '.' || dotCnt > 1)
                    return false;
            }
        }
        return (dotCnt == 0 && s.size() > 0) || (dotCnt == 1 && s.size() > 1);
    }
    bool isDigs2(string s)
    {
        int dotCnt = 0;
        if (s.size() == 0)
            return false;
        if (s[0] == '-' || s[0] == '+')
            s.erase(s.begin());
        for (auto &x : s)
        {
            if (!(x >= '0' && x <= '9'))
            {
                if (x == '.')
                    ++dotCnt;
                if (x != '.' || dotCnt > 1)
                    return false;
            }
        }
        return (dotCnt == 0 && s.size() > 0);
    }

public:
    bool isNumber(string s)
    {
        while (s[0] == ' ')
            s.erase(s.begin());
        while (s.back() == ' ')
            s.erase(s.begin() + s.size() - 1);

        if (s.size() == 0)
            return false;

        string first = "";
        string second = "";
        bool isE = false;
        for (auto &x : s)
        {
            if ((x == 'e' || x == 'E') && !isE)
            {
                isE = true;
                continue;
            }
            if (!isE)
            {
                first += x;
            }
            else
            {
                second += x;
            }
        }
        if (isE)
        {
            return isDigs(first) && isDigs2(second);
        }
        else
        {
            return isDigs(first);
        }

        return false;
    }
};
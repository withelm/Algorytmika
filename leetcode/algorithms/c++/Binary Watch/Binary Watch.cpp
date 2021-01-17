class Solution
{
private:
    vector<int> toBinary(int x)
    {
        if (x == 0)
            return {0};
        vector<int> r;
        while (x > 0)
        {
            r.push_back(x % 2);
            x /= 2;
        }
        while (r.size() < 10)
        {
            r.push_back(0);
        }
        return r;
    }
    int calc1(vector<int> &x)
    {
        int r = 0;
        for (auto &i : x)
        {
            r += i;
        }
        return r;
    }
    string toTime(vector<int> &x)
    {
        int h = 0, m = 0;
        for (int i = 0; i < 4; i++)
        {
            h *= 2;
            h += x[i];
        }
        for (int i = 4; i < 10; i++)
        {
            m *= 2;
            m += x[i];
        }
        if (h >= 12)
            return "";
        if (m >= 60)
            return "";
        if (m < 10)
        {
            return to_string(h) + ":0" + to_string(m);
        }
        if (h < 12)
            return to_string(h) + ":" + to_string(m);
        return "";
    }

public:
    vector<string> readBinaryWatch(int num)
    {
        if (num == 0)
            return {"0:00"};
        vector<string> r;
        for (int i = 0; i < (1 << 10); i++)
        {
            auto bin = toBinary(i);
            if (calc1(bin) == num)
            {
                auto tmp = toTime(bin);
                if (tmp != "")
                    r.push_back(tmp);
            }
        }
        sort(r.begin(), r.end());
        return r;
    }
};
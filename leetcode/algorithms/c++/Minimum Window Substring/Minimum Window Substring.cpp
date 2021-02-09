class Solution
{
private:
    vector<int> kt, st;
    bool check()
    {
        for (int i = 0; i < 255; i++)
        {
            if (st[i] < kt[i])
                return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t)
    {
        kt.resize(255);
        st.resize(255);

        for (auto &x : t)
            ++kt[x];
        int begin = 0;
        int end = 1;
        ++st[s[0]];
        int n = s.size();

        int r = n + 10;
        int r_b = -1;
        int r_e = -1;

        while (begin < n)
        {
            if (check())
            {
                if (end - begin < r)
                {
                    r_b = begin;
                    r_e = end;
                    r = end - begin;
                }

                --st[s[begin]];
                ++begin;
            }
            else
            {
                if (end >= n)
                    break;
                ++st[s[end]];
                ++end;
            }
        }
        string result = "";
        for (int i = r_b; i < r_e; i++)
            result += s[i];
        return result;
    }
};
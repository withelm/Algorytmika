class Solution
{
private:
    int n;
    string s;

    vector<vector<int>> pref;

    void init()
    {
        vector<int> kub(26, 0);
        pref.push_back(kub);
        for (int i = 0; i < n; i++)
        {
            ++kub[s[i] - 'a'];
            pref.push_back(kub);
        }
    }

    int calc(int x, int y)
    {
        int _min = 0;
        int _max = 0;
        vector<int> kub(26, 0);
        for (int i = 0; i < 26; i++)
        {
            kub[i] = pref[y][i] - pref[x][i];
        }
        for (int i = 0; i < 26; i++)
        {
            if (kub[i] != 0)
            {
                _max = _min = kub[i];
                break;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (kub[i] != 0)
            {
                _min = min(_min, kub[i]);
                _max = max(_max, kub[i]);
            }
        }

        return _max - _min;
    }

public:
    int beautySum(string _s)
    {
        s = _s;
        n = s.size();
        int r = 0;
        init();

        for (int i = 0; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                r += calc(i, j);
            }
        }

        return r;
    }
};
class Solution
{
private:
    vector<vector<string>> r;
    int limit, n;

    vector<string> create(string &s, int x)
    {
        int index = 1;
        string tmp = "";
        tmp = s[0];
        vector<string> res;
        for (int i = 1; i < n; i++)
        {
            if (x % 2 == 0)
            {
                res.push_back(tmp);
                tmp = s[index];
            }
            else
            {
                tmp += s[index];
            }
            x /= 2;
            ++index;
        }
        res.push_back(tmp);
        return res;
    }

    bool isPalindrome(string &x)
    {
        int m = x.size() - 1;
        for (int i = 0; i < x.size(); i++, --m)
        {
            if (x[i] != x[m])
                return false;
        }
        return true;
    }

    bool check(vector<string> &x)
    {
        for (auto &i : x)
        {
            //  cout << i << " ";
            if (!isPalindrome(i))
            {

                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s)
    {
        n = s.size();
        limit = 1 << (n - 1);

        for (int i = 0; i < limit; i++)
        {
            auto tmp = create(s, i);
            auto ans = check(tmp);
            if (ans)
                r.push_back(tmp);
            // cout << ans << endl;
        }
        return r;
    }
};
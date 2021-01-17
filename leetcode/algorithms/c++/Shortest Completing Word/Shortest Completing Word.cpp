
class Solution
{
private:
    vector<int> getKub(string &x)
    {
        vector<int> r(255, 0);
        for (auto &i : x)
        {
            if (i >= 'a' && i <= 'z')
                ++r[i];
            if (i >= 'A' && i <= 'Z')
                ++r[i - 'A' + 'a'];
        }
        return r;
    }

    bool check(vector<int> &a, vector<int> b)
    {
        for (int i = 'a'; i <= 'z'; i++)
        {
            if (a[i] > b[i])
                return false;
        }
        return true;
    }

public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        auto t = getKub(licensePlate);
        string ans = "";

        for (auto &i : words)
            if (check(t, getKub(i)))
            {
                //  r.push_back(i);
                if (ans.size() == 0)
                    ans = i;
                if (ans.size() > i.size())
                    ans = i;
            }

        return ans;
    }
};
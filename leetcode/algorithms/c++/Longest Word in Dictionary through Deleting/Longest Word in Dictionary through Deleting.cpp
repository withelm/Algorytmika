class Solution
{
private:
    bool check(string &word, string &s)
    {

        int n = s.size();
        int m = word.size();
        int i_n = 0;
        int i_m = 0;
        int cnt = 0;

        for (; i_m < m && i_n < n; i_m++)
        {
            while (i_n < n && word[i_m] != s[i_n])
                ++i_n;
            if (i_n < n && word[i_m] == s[i_n])
                ++cnt;
            ++i_n;
        }
        return cnt == m;
    }

public:
    string findLongestWord(string s, vector<string> &d)
    {
        vector<string> correct;
        for (auto &x : d)
            if (check(x, s))
                correct.push_back(x);

        sort(correct.begin(), correct.end(),
             [](string &x, string &y) {
                 if (x.size() == y.size())
                     return x < y;
                 return x.size() > y.size();
             }

        );

        if (correct.size() == 0)
            return "";

        return correct[0];
    }
};
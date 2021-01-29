class Solution
{
public:
    string reformat(string s)
    {
        vector<char> num;
        vector<char> alpha;
        for (auto &x : s)
            if (x >= '0' && x <= '9')
                num.push_back(x);
            else
                alpha.push_back(x);
        if (abs((int)alpha.size() - (int)num.size()) > 1)
            return "";
        if (alpha.size() > num.size())
            swap(alpha, num);
        string r = "";
        for (int i = 0; i < alpha.size(); i++)
        {
            r += num[i];
            r += alpha[i];
        }
        if (alpha.size() != num.size())
            r += num.back();
        return r;
    }
};
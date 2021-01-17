bool cmp(string a, string b)
{
    return a + b < b + a;
}
class Solution
{
private:
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> n;
        for (auto &x : nums)
            n.push_back(to_string(x));
        sort(n.begin(), n.end(), cmp);

        string r = "";
        for (int i = n.size() - 1; i >= 0; i--)
            r += n[i];
        while (r.size() > 0 && r[0] == '0')
        {
            r.erase(0, 1);
        }
        if (r.size() == 0)
            r = "0";
        return r;
    }
};
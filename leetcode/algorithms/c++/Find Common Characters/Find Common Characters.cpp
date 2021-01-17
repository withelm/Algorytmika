class Solution
{
private:
    int check(char c, map<string, map<char, int>> &base)
    {
        int result = 1e5;
        for (auto &x : base)
        {
            result = min(result, x.second[c]);
        }
        return result;
    }

public:
    vector<string> commonChars(vector<string> &A)
    {
        map<string, map<char, int>> base;
        for (auto &x : A)
        {
            map<char, int> kub;
            for (auto &i : x)
            {
                ++kub[i];
            }
            base[x] = kub;
        }
        vector<string> result;
        for (char i = 'a'; i <= 'z'; i++)
        {
            int limit = check(i, base);
            while (limit--)
            {
                string tmp = "";
                tmp += i;
                result.push_back(tmp);
            }
        }
        return result;
    }
};
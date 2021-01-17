class Solution
{
private:
    string generate(string name, int len)
    {
        string result = "";
        while (len > 0)
        {
            result += (len % 10) + '0';
            len /= 10;
        }
        reverse(result.begin(), result.end());
        result += " ";
        return result + name;
    }

public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        map<string, int> base;
        vector<string> result;
        for (auto &web : cpdomains)
        {
            string x = web;
            int counter = 0;
            int n = x.size();
            int i = 0;
            while (x[i] != ' ')
            {
                counter = counter * 10 + x[i] - '0';
                ++i;
            }
            x.erase(0, i + 1);
            base[x] += counter;

            while (x.size() > 0)
            {
                i = 0;
                while (x[i] != '.' && i < x.size())
                {
                    ++i;
                }
                x.erase(0, i + 1);
                base[x] += counter;
            }
        }
        base.erase("");
        for (auto &x : base)
        {
            result.push_back(generate(x.first, x.second));
        }
        return result;
    }
};
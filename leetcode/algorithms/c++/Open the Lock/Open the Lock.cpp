class Solution
{
private:
    map<string, bool> isUse;
    map<string, bool> isBlock;

public:
    int openLock(vector<string> &deadends, string target)
    {
        vector<string> q;
        int r = 0;

        for (auto &item : deadends)
            isBlock[item] = true;

        if (isBlock["0000"])
            return -1;
        if (target == "0000")
            return 0;

        q.push_back("0000");
        isUse["0000"] = true;
        while (!q.empty())
        {
            vector<string> tmp;
            for (auto &item : q)
            {
                for (int i = 0; i < 4; i++)
                {
                    for (int j = -1; j < 2; j += 2)
                    {
                        string cpy = item;
                        cpy[i] += j;
                        if (cpy[i] > '9')
                            cpy[i] = '0';
                        if (cpy[i] < '0')
                            cpy[i] = '9';
                        if (isUse[cpy])
                            continue;
                        isUse[cpy] = true;
                        if (isBlock[cpy])
                            continue;
                        tmp.push_back(cpy);
                        if (cpy == target)
                            return r + 1;
                    }
                }
            }
            ++r;
            q = tmp;
        }
        return -1;
    }
};
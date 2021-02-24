class Solution
{
private:
    vector<int> update(vector<int> t)
    {
        int n = t.size();
        vector<int> r;
        bool isUpdate = false;
        for (int i = 0; i < n; i++)
        {
            if (!isUpdate && i + 1 < n && t[i] == -2 && t[i + 1] == -1)
            {
                r.push_back(1);
                ++i;
                isUpdate = true;
            }
            else
            {
                r.push_back(t[i]);
            }
        }
        if (isUpdate)
            return r;
        r.clear();
        for (int i = 0; i < n; i++)
        {
            if (!isUpdate && i + 1 < n && t[i] > 0 && t[i + 1] > 0)
            {
                r.push_back(t[i] + t[i + 1]);
                ++i;
                isUpdate = true;
            }
            else
            {
                r.push_back(t[i]);
            }
        }
        if (isUpdate)
            return r;
        r.clear();
        for (int i = 0; i < n; i++)
        {
            if (!isUpdate && i + 2 < n && t[i] == -2 && t[i + 2] == -1 && t[i + 1] > 0)
            {
                r.push_back(2 * t[i + 1]);
                i += 2;
                isUpdate = true;
            }
            else
            {
                r.push_back(t[i]);
            }
        }
        return r;
    }

public:
    int scoreOfParentheses(string S)
    {
        if (S.size() == 0)
            return 0;

        vector<int> t;
        for (auto &x : S)
            if (x == '(')
                t.push_back(-2);
            else
                t.push_back(-1);

        while (t.size() > 1)
        {
            t = update(t);
        }
        return t[0];
    }
};
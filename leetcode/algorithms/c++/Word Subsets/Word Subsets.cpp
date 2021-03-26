class Solution
{
private:
    map<vector<int>, vector<string>> base;

    vector<int> createKub(string &item)
    {
        vector<int> kub(255, 0);
        for (auto &x : item)
            ++kub[x];
        return kub;
    }

    bool check(vector<int> k, vector<int> &t)
    {
        for (int i = 0; i < 255; i++)
        {
            if (k[i] < t[i])
                return false;
        }
        return true;
    }

public:
    vector<string> wordSubsets(vector<string> &A, vector<string> &B)
    {

        vector<int> multiKub(255, 0);
        for (auto &x : B)
        {
            auto k = createKub(x);
            for (int i = 0; i < 255; i++)
                multiKub[i] = max(multiKub[i], k[i]);
        }
        vector<string> r;
        for (auto &item : A)
        {
            if (check(createKub(item), multiKub))
            {
                r.push_back(item);
            }
        }
        return r;
    }
};
class Solution
{
private:
    int MX = 1e6;

public:
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> t(S.size() + 10, MX);
        vector<int> pos;
        int n = S.size() + 1;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == C)
            {
                t[i + 1] = 0;
                pos.push_back(i + 1);
            }
        }

        for (auto &i : pos)
        {
            //right
            int index_r = i + 1;
            int acc = 1;

            while (index_r < n && t[index_r] > acc)
            {
                t[index_r] = acc;
                ++index_r;
                ++acc;
            }
            int index_l = i - 1;
            acc = 1;
            while (index_l > 0 && t[index_l] > acc)
            {
                t[index_l] = acc;
                --index_l;
                ++acc;
            }
        }
        vector<int> result;
        for (int i = 1; i < n; i++)
        {
            result.push_back(t[i]);
        }
        return result;
    }
};
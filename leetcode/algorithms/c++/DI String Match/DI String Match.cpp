class Solution
{
public:
    vector<int> diStringMatch(string S)
    {
        vector<int> result;
        result.push_back(0);
        int min_val = -1;
        int max_val = 1;

        map<int, int> base;
        base[0] = 0;

        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == 'I')
            {
                result.push_back(max_val);
                base[max_val] = 0;
                ++max_val;
            }
            if (S[i] == 'D')
            {
                result.push_back(min_val);
                base[min_val] = 0;
                --min_val;
            }
        }

        int index = 0;
        for (auto &x : base)
        {
            x.second = index++;
        }

        for (int i = 0; i < result.size(); i++)
        {
            result[i] = base[result[i]];
        }

        return result;
    }
};
class Solution
{
private:
    char check(string &rep_str, long long int rep_cnt, int &K)
    {
        int cnt = rep_str.size() * rep_cnt;
        if (K >= cnt)
        {
            K -= cnt;
            return 0;
        }
        return rep_str[K % rep_str.size()];
    }

public:
    string decodeAtIndex(string S, int K)
    {
        long long int s = 0;
        int n = S.size();

        for (auto &x : S)
        {
            if (x >= '0' && x <= '9')
            {
                s *= x - '0';
            }
            else
            {
                ++s;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            K %= s;
            if (K == 0 && S[i] >= 'a' && S[i] <= 'z')
            {
                return (string) "" + S[i];
            }
            if (S[i] >= '0' && S[i] <= '9')
                s /= S[i] - '0';
            else
                --s;
        }

        return "ala ma kota";
    }
};
class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int P)
    {
        sort(tokens.begin(), tokens.end());

        int index = 0;
        int n = tokens.size();
        int r = 0;
        int rr = 0;

        while (index < n)
        {
            while (index < n && tokens[index] <= P)
            {
                ++rr;
                P -= tokens[index];
                r = max(rr, r);
                ++index;
                //   cout << "get" << endl;
            }
            bool check = false;
            if (rr > 0)
            {
                P += tokens[n - 1];
                --n;
                --rr;
                check = true;
                // cout << "pop" << endl;
            }
            if (!check)
                break;
        }
        return r;
    }
};
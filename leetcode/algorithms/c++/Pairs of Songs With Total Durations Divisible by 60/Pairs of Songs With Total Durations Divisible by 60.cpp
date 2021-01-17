class Solution
{
private:
    int MX = 500 + 100;

public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        vector<int> kub(MX);
        fill(kub.begin(), kub.end(), 0);
        int r = 0;
        for (auto &x : time)
        {

            r += kub[(60 - x % 60) % 60];

            ++kub[x % 60];
        }
        return r;
    }
};
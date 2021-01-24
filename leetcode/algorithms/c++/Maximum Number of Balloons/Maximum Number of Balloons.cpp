class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        map<char, int> base;
        for (auto &x : text)
            ++base[x];

        int r = base['b'];
        r = min(r, base['a']);
        r = min(r, base['l'] / 2);
        r = min(r, base['o'] / 2);
        r = min(r, base['n']);
        return r;
    }
};
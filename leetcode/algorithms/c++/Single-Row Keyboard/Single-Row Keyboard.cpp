class Solution
{
public:
    int calculateTime(string keyboard, string word)
    {
        map<int, int> base;
        int index = 0;
        for (auto &x : keyboard)
        {
            base[x] = index++;
        }
        int tmp = 0;
        int result = 0;
        for (auto &x : word)
        {
            result += abs(tmp - base[x]);
            tmp = base[x];
        }
        return result;
    }
};
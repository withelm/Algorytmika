class Solution
{
private:
public:
    bool judgeCircle(string moves)
    {
        vector<int> kub(300, 0);
        for (auto &x : moves)
        {
            ++kub[x];
        }
        return kub['U'] == kub['D'] && kub['L'] == kub['R'];
    }
};
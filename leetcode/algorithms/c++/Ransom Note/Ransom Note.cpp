class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        map<char, int> base;
        for (auto &x : ransomNote)
            --base[x];
        for (auto &x : magazine)
            ++base[x];
        for (auto &x : base)
            if (x.second < 0)
                return false;
        return true;
    }
};
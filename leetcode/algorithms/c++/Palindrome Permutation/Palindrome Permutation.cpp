class Solution
{
public:
    bool canPermutePalindrome(string s)
    {
        map<char, bool> base;
        for (auto &x : s)
            base[x] = !base[x];
        int even = 0;
        for (auto &x : base)
            even += x.second;
        return even <= 1;
    }
};
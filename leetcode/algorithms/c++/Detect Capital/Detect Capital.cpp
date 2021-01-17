class Solution
{
private:
    bool allbig(string &x)
    {
        for (auto &i : x)
        {
            if (!(i >= 'A' && i <= 'Z'))
                return false;
        }
        return true;
    }

    bool allsmall(string &x)
    {
        for (auto &i : x)
        {
            if (!(i >= 'a' && i <= 'z'))
                return false;
        }
        return true;
    }

    bool firstbig(string &x)
    {
        for (int i = 1; i < x.size(); i++)
        {
            if (!(x[i] >= 'a' && x[i] <= 'z'))
                return false;
        }
        if (!(x[0] >= 'A' && x[0] <= 'Z'))
            return false;
        return true;
    }

public:
    bool detectCapitalUse(string word)
    {
        return allbig(word) || allsmall(word) || firstbig(word);
    }
};
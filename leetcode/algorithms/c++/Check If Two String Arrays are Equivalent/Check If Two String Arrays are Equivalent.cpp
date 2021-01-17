class Solution
{

private:
    string crt(vector<string> &x)
    {
        string tmp = "";
        for (auto &i : x)
            tmp += i;
        return tmp;
    }

public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        return crt(word1) == crt(word2);
    }
};
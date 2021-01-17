class Solution
{
private:
    vector<char> block{'a', 'e', 'i', 'o', 'u'};
    string convert(char x)
    {
        for (auto &item : block)
        {
            if (x == item)
                return "";
        }
        string result = "";
        result += x;
        return result;
    }

public:
    string removeVowels(string S)
    {
        string result = "";
        for (auto &x : S)
        {
            result += convert(x);
        }
        return result;
    }
};
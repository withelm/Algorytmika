class Solution
{
private:
    vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    string toMorse(string x)
    {
        string result = "";
        for (auto &item : x)
        {
            result += morse[item - 'a'];
        }
        return result;
    }

public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        map<string, int> base;
        for (auto &x : words)
        {
            ++base[toMorse(x)];
        }
        return base.size();
    }
};
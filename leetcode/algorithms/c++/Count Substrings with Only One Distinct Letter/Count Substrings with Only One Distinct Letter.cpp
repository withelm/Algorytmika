class Solution
{
public:
    int countLetters(string S)
    {

        string tmp = "";
        char last = S[0];
        int result = 0;
        for (auto &x : S)
        {
            if (last == x)
            {
                tmp += x;
            }
            else
            {
                tmp = x;
                last = x;
            }
            result += tmp.size();
        }

        return result;
    }
};
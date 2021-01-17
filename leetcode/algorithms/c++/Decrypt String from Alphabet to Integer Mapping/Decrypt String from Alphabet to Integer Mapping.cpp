class Solution
{
public:
    string freqAlphabets(string s)
    {
        map<string, char> base;
        base["1"] = 'a';
        base["2"] = 'b';
        base["3"] = 'c';
        base["4"] = 'd';
        base["5"] = 'e';
        base["6"] = 'f';
        base["7"] = 'g';
        base["8"] = 'h';
        base["9"] = 'i';

        base["10#"] = 'j';
        base["11#"] = 'k';
        base["12#"] = 'l';
        base["13#"] = 'm';
        base["14#"] = 'n';
        base["15#"] = 'o';
        base["16#"] = 'p';
        base["17#"] = 'q';
        base["18#"] = 'r';
        base["19#"] = 's';

        base["20#"] = 't';
        base["21#"] = 'u';
        base["22#"] = 'v';
        base["23#"] = 'w';
        base["24#"] = 'x';
        base["25#"] = 'y';
        base["26#"] = 'z';

        int i = 0;
        string result = "";
        for (i = 0; i < s.size() - 2;)
        {
            string tmp = "";
            tmp += s[i];
            tmp += s[i + 1];
            tmp += s[i + 2];
            if (base[tmp] > 0)
            {
                result += base[tmp];
                i += 3;
            }
            else
            {
                string tmp2 = "";
                tmp2 += s[i];
                result += base[tmp2];
                ++i;
            }
        }
        for (; i < s.size(); i++)
        {
            string tmp2 = "";
            tmp2 += s[i];
            result += base[tmp2];
        }
        return result;
    }
};
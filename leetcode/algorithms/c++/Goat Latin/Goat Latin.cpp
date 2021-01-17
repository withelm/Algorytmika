class Solution
{
private:
    string updateStr(string x)
    {
        switch (x[0])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return x + "ma";
            break;

        default:
            char first = x[0];
            x.erase(0, 1);
            return x + first + "ma";

            break;
        }
        return x;
    }

public:
    string toGoatLatin(string S)
    {
        string result = "";
        string tmp = "";
        string last = "a";
        for (auto &it : S)
        {
            if (it != ' ')
            {
                tmp += it;
            }
            else
            {
                result += updateStr(tmp) + last + " ";
                last += "a";
                tmp.clear();
            }
        }
        result += updateStr(tmp) + last;
        return result;
    }
};
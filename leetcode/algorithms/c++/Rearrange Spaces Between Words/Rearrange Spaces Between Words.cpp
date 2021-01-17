class Solution
{
public:
    string reorderSpaces(string text)
    {
        vector<string> t;
        int whiteSpace = 0;
        string tmp = "";
        for (auto &x : text)
        {
            if (x == ' ')
            {
                ++whiteSpace;
                if (tmp != "")
                    t.push_back(tmp);
                tmp = "";
            }
            else
            {
                tmp += x;
            }
        }
        if (tmp != "")
            t.push_back(tmp);

        string result = "";
        for (int j = 0; j < t.size(); j++)
        {
            result += t[j];
            if (j < t.size() - 1)
                for (int i = 0; i < whiteSpace / (t.size() - 1); i++)
                    result += ' ';
        }
        if (t.size() != 1)
            for (int i = 0; i < whiteSpace % (t.size() - 1); i++)
                result += ' ';
        else
        {
            for (int i = 0; i < whiteSpace; i++)
                result += ' ';
        }

        return result;
    }
};
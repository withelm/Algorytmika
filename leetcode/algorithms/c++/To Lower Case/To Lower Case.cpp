class Solution
{
public:
    string toLowerCase(string str)
    {
        for (string::iterator it = str.begin(); it != str.end(); it++)
        {
            *it = tolower(*it);
        }
        return str;
    }
};
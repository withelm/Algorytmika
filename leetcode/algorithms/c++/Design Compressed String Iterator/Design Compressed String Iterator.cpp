class StringIterator
{
private:
    int index, n;
    string str;
    int LIMIT = 1e2;

public:
    StringIterator(string compressedString)
    {
        index = 0;
        n = compressedString.size();
        char zn = ' ';
        int licz = 0;
        while (index < n && str.size() < LIMIT)
        {
            if (compressedString[index] >= '0' && compressedString[index] <= '9')
            {
                licz = 10 * licz + (compressedString[index] - '0');
            }
            else
            {
                for (int i = 0; i < licz; i++)
                    str += zn;
                licz = 0;
                zn = compressedString[index];
            }

            ++index;
        }
        for (int i = 0; i < licz && str.size() < LIMIT; i++)
            str += zn;
        index = 0;
    }

    char next()
    {
        if (hasNext())
            return str[index++];
        return ' ';
    }

    bool hasNext()
    {
        return index < str.size();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
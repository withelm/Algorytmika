class CombinationIterator
{
public:
    vector<string> datas;
    vector<int> values;

    vector<string>::iterator datas_it;

    CombinationIterator(string characters, int combinationLength)
    {
        for (int i = 0; i < (1 << characters.size()); i++)
        {
            if (check(i, combinationLength))
                values.push_back(i);
        }

        for (vector<int>::iterator it = values.begin(); it != values.end(); it++)
        {
            datas.push_back(getString(characters, *it));
        }
        sort(datas.begin(), datas.end());
        datas_it = datas.begin();
    }

    string getString(string source, int n)
    {
        string result = "";
        int index = 0;
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                result += source[index];
            }
            n /= 2;
            ++index;
        }
        return result;
    }

    bool check(int n, int k)
    {
        int r = 0;
        while (n > 0)
        {
            r += (n % 2);
            n /= 2;
        }
        return r == k;
    }

    string next()
    {
        string result = *datas_it;
        ++datas_it;
        return result;
    }

    bool hasNext()
    {
        return datas_it != datas.end();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
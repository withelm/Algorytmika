class Solution
{
private:
    bool check(int i, string &x)
    {
        if (i < 1)
            return false;
        if (x[i - 1] >= 'A' && x[i - 1] <= 'Z' && x[i] >= 'a' && x[i] <= 'z')
        {
            return x[i - 1] == (x[i] - 'a') + 'A';
        }
        if (x[i] >= 'A' && x[i] <= 'Z' && x[i - 1] >= 'a' && x[i - 1] <= 'z')
        {
            return x[i - 1] == (x[i] - 'A') + 'a';
        }
        return false;
    }

public:
    string makeGood(string s)
    {
        int index = 1;
        while (index < s.size())
        {
            // cout << index << " " << s << endl;
            if (check(index, s))
            {
                s.erase(s.begin() + index);
                s.erase(s.begin() + index - 1);

                index = index - 2;
            }
            ++index;
        }

        return s;
    }
};
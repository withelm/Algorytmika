class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int n = name.size();
        int m = typed.size();

        if (m < n)
            return false;
        if (name[0] != typed[0])
            return false;

        int index = 0;
        int index2 = 0;

        while (index < n)
        {
            //  cout << index  << " " << name[index] << " " << index2 << " " << typed[index2] << endl;
            map<char, int> base;
            while (index2 < m && name[index] != typed[index2])
            {
                ++base[typed[index2]];
                ++index2;
            }

            if (base.size() > 1)
                return false;
            if (index2 >= m)
                return false;
            ++index2;

            ++index;
        }
        map<char, int> base;
        for (; index2 < m; index2++)
            ++base[typed[index2]];
        base[name.back()] = 1;

        return base.size() == 1;
    }
};
class Solution
{
public:
    int numSpecialEquivGroups(vector<string> &A)
    {
        map<vector<string>, int> base;
        for (auto &x : A)
        {
            string first = "";
            string second = "";
            for (int i = 0; i < x.size(); i++)
            {
                if (i % 2 == 0)
                    first += x[i];
                else
                    second += x[i];
            }
            sort(first.begin(), first.end());
            sort(second.begin(), second.end());
            // cout << first << " " << second << endl;
            ++base[{first, second}];
        }

        return base.size();
    }
};
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> r;
        if (numRows == 0)
            return r;

        vector<int> tmp;
        tmp.push_back(1);

        r.push_back(tmp);

        for (int i = 2; i <= numRows; i++)
        {

            vector<int> t;
            t.push_back(1);

            vector<int> p = r.back();
            for (int j = 1; j < p.size(); j++)
            {
                t.push_back(p[j - 1] + p[j]);
            }
            t.push_back(1);
            r.push_back(t);
        }
        return r;
    }
};
class Point
{
public:
    int val, odl, index;
};

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<Point> t;
        int i = 0;
        for (auto &item : arr)
        {
            Point tmp;
            tmp.val = item;
            tmp.odl = abs(item - x);
            tmp.index = i++;
            t.push_back(tmp);
        }

        sort(t.begin(), t.end(), [](const Point &a, const Point &b)
             {
                 if (a.odl == b.odl)
                 {
                     return a.val < b.val;
                 }
                 return a.odl < b.odl;
             });

        vector<int> res;
        for (i = 0; i < k; i++)
            res.push_back(t[i].val);
        sort(res.begin(), res.end());
        return res;
    }
};
class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        int r = 1e9;
        vector<string> res;
        for (int i = 0; i < list1.size(); i++)
        {
            for (int j = 0; j < list2.size(); j++)
            {
                if (list1[i] == list2[j])
                {
                    if (i + j < r)
                    {
                        res = {list1[i]};
                        r = i + j;
                    }
                    else if (i + j == r)
                    {
                        res.push_back(list1[i]);
                    }
                }
            }
        }
        return res;
    }
};
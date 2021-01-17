class Solution
{
public:
    int distributeCandies(vector<int> &candies)
    {

        set<int> datas;
        for (auto &x : candies)
        {
            datas.insert(x);
        }
        return min(candies.size() / 2, datas.size());
    }
};
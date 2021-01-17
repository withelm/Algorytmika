class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {

        while (stones.size() > 1)
        {
            sort(stones.begin(), stones.end());

            int v1 = stones[stones.size() - 1];
            int v2 = stones[stones.size() - 2];

            stones.pop_back();
            stones.pop_back();
            if (v1 > v2)
            {
                stones.push_back(v1 - v2);
            }
        }
        if (stones.size() == 0)
            return 0;
        return stones[0];
    }
};
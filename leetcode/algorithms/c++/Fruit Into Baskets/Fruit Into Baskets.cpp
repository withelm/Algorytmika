class Solution
{
public:
    int totalFruit(vector<int> &tree)
    {
        int result = 0;
        int current = 0;
        map<int, int> base;
        auto index = tree.begin();
        for (auto &x : tree)
        {
            ++base[x];
            ++current;
            if (base.size() <= 2)
            {
                result = max(result, current);
            }
            else
            {
                while (base.size() > 2)
                {
                    --base[*index];
                    --current;
                    if (base[*index] == 0)
                    {
                        base.erase(*index);
                    }
                    ++index;
                }
            }
        }
        return result;
    }
};
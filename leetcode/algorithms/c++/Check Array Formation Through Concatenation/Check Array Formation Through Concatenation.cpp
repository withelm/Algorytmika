class Solution
{
public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
    {
        map<int, vector<int>> base;
        for (auto &x : pieces)
        {
            base[x[0]] = x;
        }

        int index = 0;
        int n = arr.size();

        for (; index < n;)
        {

            if (base.find(arr[index]) == base.end())
                return false;
            int index_tmp = index;
            auto tmp = base[arr[index]];

            for (auto &x : tmp)
            {

                if (arr[index] != x)
                    return false;
                ++index;
            }
        }
        return true;
    }
};
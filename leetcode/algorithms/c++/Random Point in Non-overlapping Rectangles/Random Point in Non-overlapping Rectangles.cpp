class Solution
{
private:
    vector<vector<int>> recList;
    vector<int> v;
    int n;
    int k;

public:
    Solution(vector<vector<int>> &rects)
    {
        recList.clear();
        v.clear();
        n = 0;
        k = 0;
        int area = 0;
        for (auto &x : rects)
        {
            if (rects.size() > 0)
            {
                recList.push_back(x);
                area += (x[2] - x[0] + 1) * (x[3] - x[1] + 1);
                v.push_back(area);
            }
            else
            {
                ++n;
            }
        }
    }

    vector<int> pick()
    {
        int someArea = rand() % v.back();

        int index = upper_bound(v.begin(), v.end(), someArea) - v.begin();

        int x = rand() % (recList[index][2] - recList[index][0] + 1) + recList[index][0];
        int y = rand() % (recList[index][3] - recList[index][1] + 1) + recList[index][1];
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
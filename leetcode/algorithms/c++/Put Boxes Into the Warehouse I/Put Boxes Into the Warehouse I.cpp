class Solution
{
private:
    int n;

public:
    int maxBoxesInWarehouse(vector<int> &boxes, vector<int> &warehouse)
    {
        n = warehouse.size();

        for (int i = 1; i < n; i++)
        {
            warehouse[i] = min(warehouse[i - 1], warehouse[i]);
        }
        reverse(warehouse.begin(), warehouse.end());
        sort(boxes.begin(), boxes.end());

        int i = 0;
        int res = 0;
        for (auto box : boxes)
        {
            while (i < n && box > warehouse[i])
                ++i;
            if (i == n)
                break;
            if (box <= warehouse[i])
            {
                ++res;
                ++i;
            }
        }

        return res;
    }
};
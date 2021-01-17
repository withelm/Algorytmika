class Solution
{
private:
    int RIGHT_LIMIT = 1e9 + 100;

    bool check(vector<int> &houses, vector<int> &heaters, int k)
    {
        int n = houses.size();
        int m = heaters.size();

        for (auto &x : houses)
        {
            int min_x = x - k;
            int max_x = x + k;
            auto low = lower_bound(heaters.begin(), heaters.end(), min_x);
            auto high = upper_bound(heaters.begin(), heaters.end(), max_x);
            if (high - low == 0)
                return false;
        }
        return true;
    }

public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(heaters.begin(), heaters.end());

        int left = 0;
        int right = RIGHT_LIMIT;
        int mid = (left + right) / 2;
        while (left <= right)
        {
            //cout << mid << " " << check(houses, heaters, mid) << endl;
            if (check(houses, heaters, mid))
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }
        //cout << left << " " << mid << " " << right << endl;
        if (right >= 0 && check(houses, heaters, right))
            return right;
        if (mid >= 0 && check(houses, heaters, mid))
            return mid;

        return left;
    }
};
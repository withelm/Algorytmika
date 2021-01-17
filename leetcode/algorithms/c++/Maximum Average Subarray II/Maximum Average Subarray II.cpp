class Solution
{
private:
    double EPS = 1e-6;
    vector<int> t;
    int n;

    bool check(double mid, int k)
    {
        double sum = 0;
        double begin_sum = 0;
        double begin_min_sum = 0;
        for (int i = 0; i < k; i++)
            sum += t[i] - mid;
        if (sum >= 0)
            return true;
        for (int i = k; i < n; i++)
        {
            sum += t[i] - mid;
            begin_sum += t[i - k] - mid;
            begin_min_sum = min(begin_sum, begin_min_sum);
            if (sum >= begin_min_sum)
                return true;
        }
        return false;
    }

public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        t = nums;
        n = t.size();

        double right = 1e18;
        double left = -right;

        double mid = 0;
        while (abs(left - right) > EPS)
        {
            mid = (right + left) / 2;
            cout << left << " " << mid << " " << right << endl;
            if (check(mid, k))
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};
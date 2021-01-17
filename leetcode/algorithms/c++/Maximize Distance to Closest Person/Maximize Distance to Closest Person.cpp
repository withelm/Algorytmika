class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int left = 0;
        int n = seats.size();
        int right = n - 1;
        int r = 0;
        while (left < n && seats[left] == 0)
            ++left;
        r = max(left, r);
        while (right >= 0 && seats[right] == 0)
            --right;
        r = max(n - right - 1, r);

        bool isStart = false;
        int begin = left;
        for (int i = left; i <= right; i++)
        {
            if (seats[i] == 1)
            {
                //cout << i << " " << begin << endl;
                r = max(r, (i - begin) / 2);
                begin = i;
            }
        }
        return r;
    }
};
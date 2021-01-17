class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        vector<int> t(2 * n, 0);
        int sum = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            t[i % n] = gas[i % n] - cost[i % n];
            if (i / n == 0)
                sum += t[i];
        }
        if (sum < 0)
            return -1;

        int tmp_sum = t[0];
        int index_begin = 0;
        int index_end = 1;
        while (index_begin < 2 * n && index_end < 2 * n)
        {
            if (tmp_sum < 0)
            {
                tmp_sum -= t[index_begin];
                ++index_begin;
            }
            else
            {
                tmp_sum += t[index_end];
                ++index_end;
            }
            if (index_begin == index_end)
            {
                tmp_sum = t[index_begin];
                index_end = index_begin + 1;
            }
        }
        return index_begin % n;
    }
};
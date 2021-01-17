public class Solution
{
    public int KthFactor(int n, int k)
    {
        int t = 0;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                ++t;
                if (k == t) return i;
            }
        }
        return -1;
    }
}
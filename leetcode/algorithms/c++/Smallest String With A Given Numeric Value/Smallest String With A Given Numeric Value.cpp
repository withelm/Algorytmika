class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string r(n, 'a');
        k -= n;

        for (int i = n - 1; i >= 0 && k > 0; i--)
        {
            if ('z' - 'a' > k)
            {
                r[i] += k;
                k -= k;
                break;
            }
            else
            {
                r[i] = 'z';
                k -= 'z' - 'a';
            }
        }

        return r;
    }
};
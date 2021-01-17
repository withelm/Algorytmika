/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        int l = 1;
        int r = n;
        int m = 0;

        while (l < r)
        {
            m = (r - l) / 2 + l;
            cout << l << " " << m << " " << r << endl;
            int v = guess(m);
            if (v == 0)
                return m;
            if (v == -1)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        cout << l << " " << m << " " << r << endl;
        if (guess(l) == 0)
            return l;
        if (guess(r) == 0)
            return r;
        return m;
    }
};
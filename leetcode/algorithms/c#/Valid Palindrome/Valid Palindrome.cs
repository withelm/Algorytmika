public class Solution
{
    public bool IsPalindrome(string s)
    {
        var t = s
                .ToLower()
                .Where(x => (x >= 'a' && x <= 'z') || (x >= '0' && x <= '9'))
                .ToArray();
        int i = 0;
        int n = t.Count() - 1;
        while (i < n)
        {
            if (t[i] != t[n]) return false;
            ++i;
            --n;
        }
        return true;
    }
}

public class Solution
{
    public bool IsMatch(string s, string p)
    {
        p = "^" + p + "$";
        return System.Text.RegularExpressions.Regex.IsMatch(s, p);
    }
}

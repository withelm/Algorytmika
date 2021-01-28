public class Solution
{
    public bool CheckRecord(string s)
    {
        return s.Count(x => x == 'A') <= 1 && s.IndexOf("LLL") == -1;
    }
}

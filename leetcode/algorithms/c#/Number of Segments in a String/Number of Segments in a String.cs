using System.Linq;
public class Solution
{
    public int CountSegments(string s)
    {
        return s.Split(' ').Where(x => !string.IsNullOrEmpty(x)).Count();
    }
}
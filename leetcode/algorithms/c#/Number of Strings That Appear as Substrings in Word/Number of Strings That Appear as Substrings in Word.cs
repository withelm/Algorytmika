public class Solution
{
    public int NumOfStrings(string[] patterns, string word) =>
        patterns.ToList().Count(x => word.Contains(x));
}

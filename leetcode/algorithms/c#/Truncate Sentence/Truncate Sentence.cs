public class Solution
{
    public string TruncateSentence(string s, int k) =>
        String.Join(" ", s.Split(' ').Take(k));
}

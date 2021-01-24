public class Solution
{
    public int MaxRepeating(string sequence, string word)
    {
        string t = word;
        while (sequence.IndexOf(t, 0) != -1)
        {
            t += word;
        }
        return (t.Count() / word.Count()) - 1;
    }
}

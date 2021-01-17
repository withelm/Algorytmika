public class Solution
{
    public string ReverseWords(string s)
    {
        var l = s.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
        l.Reverse();

        return string.Join(" ", l);
    }
}
public class Solution
{
    private string ReverseString(string s)
    {
        char[] arr = s.ToCharArray();
        Array.Reverse(arr);
        return new string(arr);
    }
    public string ReverseWords(string s)
    {
        var sL = s.Split(' ');
        string r = string.Empty;
        foreach (var item in sL)
        {
            r += ReverseString(item) + " ";
        }
        return r.Trim();
    }
}
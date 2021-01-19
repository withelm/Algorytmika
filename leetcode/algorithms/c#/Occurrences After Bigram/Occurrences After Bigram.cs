public class Solution
{
    public string[] FindOcurrences(string text, string first, string second)
    {
        var words = text.Split(' ');
        List<string> r = new List<string>();
        for (int i = 0; i + 2 < words.Count(); i++)
        {
            if (words[i] == first && words[i + 1] == second)
                r.Add(words[i + 2]);
        }
        return r.ToArray();
    }
}
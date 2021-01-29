using System.Linq;

public class Solution
{
    public IList<string> StringMatching(string[] words)
    {
        List<string> r = new List<string>();

        int n = words.Count();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;
                if (words[i].IndexOf(words[j]) != -1)
                {
                    r.Add(words[j]);
                }
            }
        }

        return r.Distinct().ToList();
    }
}

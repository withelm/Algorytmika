public class Solution
{
    public IList<string> TopKFrequent(string[] words, int k)
    {
        Dictionary<string, int> t = new Dictionary<string, int>();
        foreach (var item in words)
        if (t.ContainsKey(item))
            ++t[item];
        else
            t.Add(item, 1);

        return t
            .OrderByDescending(x => x.Value)
            .ThenBy(c => c.Key)
            .Take(k)
            .Select(x => x.Key)
            .ToArray();
    }
}

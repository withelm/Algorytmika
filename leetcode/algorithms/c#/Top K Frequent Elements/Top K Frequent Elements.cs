using System.Linq;

public class Solution
{
    public int[] TopKFrequent(int[] nums, int k)
    {
        Dictionary<int, int> t = new Dictionary<int, int>();
        foreach (var item in nums)
        if (t.ContainsKey(item))
            ++t[item];
        else
            t.Add(item, 1);

        return t
            .OrderByDescending(x => x.Value)
            .Take(k)
            .Select(x => x.Key)
            .ToArray();
    }
}

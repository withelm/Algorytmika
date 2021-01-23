public class Solution
{
    public int[][] IndexPairs(string text, string[] words)
    {
        List<(int, int)> r = new List<(int, int)>();
        foreach (var word in words)
        {
            for (int i = 0; i < text.Count(); )
            {
                int val = text.IndexOf(word, i);
                if (val == -1) break;
                r.Add((val, val + word.Count() - 1));
                i = val + 1;
            }
        }
        r.Sort((x, y) =>
            {
                if (x.Item1 == y.Item1) return x.Item2.CompareTo(y.Item2);
                return x.Item1.CompareTo(y.Item1);
            });
            
        int[][] result = new int[r.Count()][];

        int index = 0;
        foreach (var item in r)
        {
            result[index++] = new int[] { item.Item1, item.Item2 };
        }

        return result;
    }
}

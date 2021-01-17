public class Solution
{
    public int NumUniqueEmails(string[] emails)
    {
        Dictionary<string, int> result = new Dictionary<string, int>();
        foreach (var item in emails)
        {
            var t = item.Split('@');
            t[0] = t[0].Replace(".", string.Empty);

            string source = t[0].Split('+')[0] + '@' + t[1];
            if (!result.ContainsKey(source))
                result.Add(source, 0);
        }

        return result.Count;
    }
}
public class Solution
{
    private void Add(List<string> t, Dictionary<string, int> d)
    {
        foreach (var item in t)
        {
            if (d.ContainsKey(item))
                ++d[item];
            else
                d.Add(item, 1);
        }
    }

    private List<string> Find(Dictionary<string, int> a, Dictionary<string, int> b)
    {
        List<string> r = new List<string>();
        foreach (var item in a)
        {
            if (item.Value == 1 && !b.ContainsKey(item.Key))
                r.Add(item.Key);
        }
        return r;
    }

    public string[] UncommonFromSentences(string A, string B)
    {
        var alist = A.Split(' ').ToList();
        var blist = B.Split(' ').ToList();

        Dictionary<string, int> aDic = new Dictionary<string, int>();
        Dictionary<string, int> bDic = new Dictionary<string, int>();

        Add(alist, aDic);
        Add(blist, bDic);




        List<string> r = new List<string>();

        r.AddRange(Find(aDic, bDic));
        r.AddRange(Find(bDic, aDic));

        return r.ToArray();
    }
}
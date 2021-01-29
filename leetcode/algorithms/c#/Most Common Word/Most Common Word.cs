using System.Linq;

public class Solution
{
    private string clear(string x)
    {
        string result = string.Empty;
        foreach (var item in x.ToLower())
        {
            if (item >= 'a' && item <= 'z') result += item;
        }
        return result;
    }

    public string MostCommonWord(string paragraph, string[] banned)
    {
        Dictionary<string, int> dic = new Dictionary<string, int>();
        paragraph = paragraph.ToLower();

        string result = string.Empty;
        int count = 0;

        foreach (var item in paragraph
                .Split(new char[] { '!', '?', '\'', ',', ';', '.', ' ' }, StringSplitOptions.RemoveEmptyEntries)
                .Where(x => !banned.Any(y => clear(x) == y)))
        {
            var item2 = clear(item);
            if (dic.ContainsKey(item2))
            {
                ++dic[item2];
            }
            else
            {
                dic.Add(item2, 1);
            }
            if (count < dic[item2])
            {
                count = dic[item2];
                result = item2;
            }
        }

        return result;
    }
}

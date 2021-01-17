public class Solution
{
    public bool WordPattern(string pattern, string str)
    {
        var strList = str.Split(' ');
        Dictionary<char, string> data = new Dictionary<char, string>();
        Dictionary<string, int> blockWord = new Dictionary<string, int>();
        if (pattern.Length != strList.Count()) return false;
        int i = 0;
        foreach (var item in pattern)
        {
            if (!data.ContainsKey(item))
            {
                if (blockWord.ContainsKey(strList[i]))
                    return false;
                blockWord.Add(strList[i], 1);
                data.Add(item, strList[i]);
            }
            else
            {
                if (data[item] != strList[i])
                    return false;
            }
            ++i;
        }

        return true;
    }
}
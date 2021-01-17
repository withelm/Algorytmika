public class Solution
{
    public int CompareVersion(string version1, string version2)
    {
        var ver1List = version1.Split('.');
        var ver2List = version2.Split('.');

        int index = 0;
        while (index < ver1List.Count() && index < ver2List.Count())
        {
            var val1Int = Int32.Parse(ver1List[index]);
            var val2Int = Int32.Parse(ver2List[index]);
            if (val1Int > val2Int)
                return 1;
            if (val1Int < val2Int)
                return -1;
            ++index;
        }
        while (index < ver1List.Count())
        {
            var val1Int = Int32.Parse(ver1List[index]);
            if (val1Int > 0)
                return 1;
            ++index;
        }
        while (index < ver2List.Count())
        {
            var val2Int = Int32.Parse(ver2List[index]);
            if (val2Int > 0)
                return -1;
            ++index;
        }
        return 0;
    }
}
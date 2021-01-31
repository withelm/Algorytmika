using System.Linq;

public class Solution
{
    public string SimplifyPath(string path)
    {
        var folderNames = path.Split('/');
        List<string> result = new List<string>();
        foreach (var item in folderNames)
        {
            if (item == string.Empty) continue;
            if (item == ".") continue;
            if (item == "..")
            {
                if (result.Any())
                {
                    result.RemoveAt(result.Count - 1);
                }
                continue;
            }
            result.Add (item);
        }

        return "/" + String.Join("/", result);
    }
}

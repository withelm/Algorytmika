public class Solution
{
    public string ReformatNumber(string number)
    {
        var tmp = number.Replace("-", "").Replace(" ", "");
        string r = "";
        int i = 0;
        int n = tmp.Count();

        for (; i + 4 < n; i += 3)
        {

            r += $"{tmp[i]}{tmp[i + 1]}{tmp[i + 2]}-";
        }
        // Console.WriteLine(n - i);
        switch (n - i)
        {
            case 2:
                r += $"{tmp[i]}{tmp[i + 1]}";
                break;
            case 3:
                r += $"{tmp[i]}{tmp[i + 1]}{tmp[i + 2]}";
                break;
            case 4:
                r += $"{tmp[i]}{tmp[i + 1]}-{tmp[i + 2]}{tmp[i + 3]}";
                break;
        }

        return r;
    }
}
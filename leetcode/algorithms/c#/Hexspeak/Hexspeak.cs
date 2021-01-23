public class Solution
{
    public string ToHexspeak(string num)
    {
        var val =
            long.Parse(num).ToString("X").Replace("1", "I").Replace("0", "O");
        if (val.Any(x => x >= '2' && x <= '9')) return "ERROR";
        return val;
    }
}

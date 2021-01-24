public class Solution
{
    public int DaysBetweenDates(string date1, string date2)
    {
        var dt1 = DateTime.Parse(date1);
        var dt2 = DateTime.Parse(date2);
        return Math.Abs((dt2 - dt1).Days);
    }
}

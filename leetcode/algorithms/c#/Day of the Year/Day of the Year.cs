public class Solution
{
    public int DayOfYear(string date)
    {
        return DateTime.Parse(date).DayOfYear;
    }
}

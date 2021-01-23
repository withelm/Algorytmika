public class Solution
{
    public string DayOfTheWeek(int day, int month, int year)
    {
        return new DateTime(year, month, day).DayOfWeek.ToString();
    }
}

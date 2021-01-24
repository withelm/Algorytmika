public class Solution
{
    public int NumberOfDays(int Y, int M)
    {
        var dt1 = new DateTime(Y, M, 1);
        var dt2 = new DateTime(Y, M, 1).AddMonths(1);
        return (dt2 - dt1).Days;
    }
}

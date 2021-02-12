public class Solution
{
    public int NumberOfSteps(int num)
    {
        if (num == 0) return 0;
        if (num == 1) return 1;
        if (num % 2 == 0) return NumberOfSteps(num / 2) + 1;
        return NumberOfSteps(num - 1) + 1;
    }
}

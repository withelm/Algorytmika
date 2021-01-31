using System.Linq;

public class Solution
{
    public int MyAtoi(string s)
    {
        s = s.Trim();
        long r = 0;
        int index = 0;
        bool minus = false;
        if (s.Count() == 0) return 0;
        if (s[index] == '-')
        {
            minus = true;
            ++index;
            if (s.Count() == 1) return 0;
        }
        if (index == 0 && s[index] == '+') ++index;
        while (index < s.Count() && s[index] >= '0' && s[index] <= '9')
        {
            r = (s[index] - '0') + r * 10;
            if (r > Int32.MaxValue)
            {
                if (minus) return Int32.MinValue;
                return Int32.MaxValue;
            }
            ++index;
        }
        if (minus) r *= -1;
        return (int) r;
    }
}

public class Solution
{
    public string RemoveDuplicates(string s, int k)
    {
        int oldLen = s.Count();
        while (true)
        {
            bool isChange = false;
            for (char i = 'a'; i <= 'z'; i++)
            {
                string source = new String(i, k);
                s = s.Replace(source, string.Empty);
                if (oldLen > s.Count())
                {
                    isChange = true;
                    oldLen = s.Count();
                }
            }
            if (!isChange) break;
        }
        return s;
    }
}

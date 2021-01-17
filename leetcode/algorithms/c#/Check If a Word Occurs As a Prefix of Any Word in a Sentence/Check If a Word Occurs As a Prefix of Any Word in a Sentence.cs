public class Solution
{

    private bool check(string a, string w)
    {
        if (a.Count() < w.Count()) return false;
        for (int i = 0; i < w.Length; i++)
        {
            if (a[i] != w[i]) return false;
        }
        return true;
    }

    public int IsPrefixOfWord(string sentence, string searchWord)
    {
        var words = sentence.Split(' ');
        for (int i = 0; i < words.Length; i++)
        {
            if (check(words[i], searchWord))
            {
                return i + 1;
            }
        }
        return -1;
    }
}
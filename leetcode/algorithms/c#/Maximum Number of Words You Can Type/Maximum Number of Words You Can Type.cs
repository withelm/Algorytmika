public class Solution
{
    public int CanBeTypedWords(string text, string brokenLetters) =>
        text.Split(' ').Count(x => !brokenLetters.Any(y => x.Contains(y)));
}

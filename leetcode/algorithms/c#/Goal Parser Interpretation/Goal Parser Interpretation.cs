public class Solution
{
    public string Interpret(string command)
    {
        return command.Replace("()", "o").Replace("(", "").Replace(")", "");

    }
}
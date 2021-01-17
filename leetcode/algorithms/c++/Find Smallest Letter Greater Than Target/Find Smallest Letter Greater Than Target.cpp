class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int index = 0;
        int n = letters.size();
        while (index < n && letters[index] <= target)
            ++index;
        if (index == n)
            return letters[0];
        return letters[index];
    }
};
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution
{
private:
    int rand(int n)
    {
        int result = rand7();
        while (result > n)
            result = rand7();
        return result;
    }

public:
    int rand10()
    {
        int x = rand(5);
        int y = rand(2);
        if (y == 2)
            return x + 5;
        return x;
    }
};
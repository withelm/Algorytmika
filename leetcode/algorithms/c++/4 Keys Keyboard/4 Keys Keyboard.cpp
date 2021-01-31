class Solution
{
private:
    vector<int> first = {-1, 1, 2, 3, 4, 5, 6, 9, 12, 16, 20, 27, 36, 48, 64, 81};

public:
    int maxA(int N)
    {
        if (N < 16)
            return first[N];
        return 4 * maxA(N - 5);
    }
};
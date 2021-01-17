class Solution
{
private:
    int kg(int N, int K)
    {
        if (N == 1)
            return 0;

        int half = (1 << (N - 1)) / 2;

        if (K <= half)
            return kg(N - 1, K);
        return (1 + kg(N - 1, K - half)) % 2;
    }

public:
    int kthGrammar(int N, int K)
    {
        return kg(N, K);
    }
};
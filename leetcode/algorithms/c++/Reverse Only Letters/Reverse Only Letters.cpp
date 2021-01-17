class Solution
{
public:
    string reverseOnlyLetters(string S)
    {
        int begin = 0;
        int end = S.size() - 1;

        while (begin < end)
        {
            if (!((S[begin] >= 'a' && S[begin] <= 'z') || (S[begin] >= 'A' && S[begin] <= 'Z')))
            {
                ++begin;
                continue;
            }
            if (!((S[end] >= 'a' && S[end] <= 'z') || (S[end] >= 'A' && S[end] <= 'Z')))
            {
                --end;
                continue;
            }
            swap(S[begin], S[end]);
            ++begin;
            --end;
        }
        return S;
    }
};
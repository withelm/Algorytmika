class Solution
{
public:
    bool rotateString(string A, string B)
    {
        if (A.size() != B.size())
            return false;
        int n = A.size();

        for (int i = 0; i < n; i++)
        {
            if (A == B)
                return true;
            A.push_back(A[0]);
            A.erase(A.begin());
        }
        return A == B;
    }
};
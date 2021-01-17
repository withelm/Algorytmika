class Solution
{
private:
    bool checkStr(string &a, string &b)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }

public:
    int t[255];
    bool buddyStrings(string A, string B)
    {
        if (A.size() != B.size())
            return false;

        int n = A.size();

        vector<int> diff_index;

        for (int i = 0; i < 255; i++)
        {
            t[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {

            if (A[i] != B[i])
                diff_index.push_back(i);
            ++t[A[i]];
        }
        if (diff_index.size() == 0)
        {
            for (int i = 0; i < 255; i++)
            {
                if (t[i] >= 2)
                    return true;
            }
            return false;
        }
        else
        {
            if (diff_index.size() == 2)
            {
                swap(A[diff_index[0]], A[diff_index[1]]);
                return checkStr(A, B);
            }
            else
            {
                return false;
            }
        }
    }
};
class Solution
{
public:
    bool confusingNumber(int N)
    {
        vector<int> dig;
        int lastN = N;
        while (N > 0)
        {
            int val = N % 10;
            if (val == 2 || val == 3 || val == 4 || val == 5 || val == 7)
                return false;
            dig.push_back(N % 10);
            N /= 10;
        }
        int newN = 0;
        for (int i = 0; i < dig.size(); i++)
        {
            switch (dig[i])
            {
            case 0:
                newN = 10 * newN + 0;
                break;
            case 1:
                newN = 10 * newN + 1;
                break;
            case 9:
                newN = 10 * newN + 6;
                break;
            case 8:
                newN = 10 * newN + 8;
                break;
            case 6:
                newN = 10 * newN + 9;
                break;
            }
        }
        return newN != lastN;
    }
};
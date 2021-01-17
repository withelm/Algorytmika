class Solution
{
private:
    bool check(int x)
    {
        int tmp_x = x;
        int y = 0;
        vector<int> r;
        while (x > 0)
        {
            r.push_back(x % 10);
            x /= 10;
        }

        reverse(r.begin(), r.end());
        for (auto &i : r)
        {
            switch (i)
            {
            case 0:
                y = y * 10 + 0;
                break;
            case 1:
                y = y * 10 + 1;
                break;
            case 2:
                y = y * 10 + 5;
                break;

            case 5:
                y = y * 10 + 2;
                break;
            case 6:
                y = y * 10 + 9;
                break;

            case 8:
                y = y * 10 + 8;
                break;
            case 9:
                y = y * 10 + 6;
                break;
            default:
                return false;
            }
        }

        return tmp_x != y;
    }

public:
    int rotatedDigits(int N)
    {
        int r = 0;
        for (int i = 1; i <= N; i++)
        {
            //cout << i << ": " << check(i) << endl;
            r += check(i);
        }
        return r;
    }
};
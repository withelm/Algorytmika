class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int lastA = 1;
        int lastB = area;
        for (int i = 2; i * i <= area; i++)
        {
            if (area % i == 0)
            {
                lastA = i;
                lastB = area / i;
            }
        }
        return {lastB, lastA};
    }
};
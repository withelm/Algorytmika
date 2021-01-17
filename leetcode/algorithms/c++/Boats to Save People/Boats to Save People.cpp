class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int r = 0;
        int begin = 0;
        int n = people.size();
        int end = n - 1;

        while (begin <= end)
        {
            if (people[begin] + people[end] <= limit)
            {
                ++begin;
                --end;
            }
            else
            {
                --end;
            }
            ++r;
        }
        return r;
    }
};
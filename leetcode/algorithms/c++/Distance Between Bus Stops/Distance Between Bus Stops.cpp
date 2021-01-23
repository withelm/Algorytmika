class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        if (start > destination)
            swap(start, destination);
        int r = 0;
        for (int i = start; i < destination; i++)
            r += distance[i];
        int r2 = 0;
        for (int i = destination; i < start + distance.size(); i++)
            r2 += distance[i % distance.size()];
        return min(r, r2);
    }
};
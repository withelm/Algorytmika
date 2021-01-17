class Solution
{
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
    {
        int n = startTime.size();

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result += startTime[i] <= queryTime && endTime[i] >= queryTime;
        }
        return result;
    }
};